import { createServer } from "http";
import { Server, Socket } from "socket.io";
import User from "./user";
import Logger from "../util/logger";
import Room from "./room";
import Connection from "./connection";

class GameServer
{
    static instance : GameServer;

    io : Server;
    httpServer;
    rooms : {[key: string]: Room} = {};
    users : {[key: string]: User} = {};
    
    constructor()
    {
        this.httpServer = createServer();
        this.io = new Server(this.httpServer, {
            cors: {
                origin: "http://localhost:5000",
                methods: ["GET", "POST"]
            }
        });
        GameServer.instance = this;
    }

    listen(port: number) : void
    {
        this.io.on("connection", (socket: Socket) => {
            this.registerEvents(new Connection(null, socket));
        });
        
        this.httpServer.listen(port);
        Logger.info(`Listening on port ${port}`);
    }

    getUserList(room: Room = undefined) : {[key: string]: {username: string, score: number}}
    {
        let list = {};

        if (room !== undefined) {
            for (const [token, user] of Object.entries(room.users))
                list[user.id] = {username: user.name, score: user.score};
        } else {
            for (const [token, user] of Object.entries(this.users))
                list[user.id] = {username: user.name, score: user.score};
        }
        return list;
    }

    registerEvents(conn: Connection) : void
    {
        let ipAddr = conn.socket.request.connection.remoteAddress;
        Logger.info(`Connection recieved from ${ipAddr}`)
        this.registerAuthEvent(conn);
        this.registerDisconnectEvent(conn);
    }

    registerAuthEvent(conn: Connection) : void
    {
        let server = this;
        let ipAddr = conn.socket.request.connection.remoteAddress;
        conn.socket.on("auth", (data: {username: string, token: string, roomID: string}) => {
            Logger.info(`Authenticating ${data.username} [${ipAddr}]`, "AUTH");
            User.authenticate(data, conn);
            if (data.roomID === undefined || !(data.roomID in server.rooms)) {
                let roomID;
                do {
                    roomID = server.generateToken(6);
                } while (roomID in server.rooms);
                Logger.info(`Creating room ID ${roomID}`, "AUTH");
                server.rooms[roomID] = conn.user.createRoom(roomID);
            } else {
                Logger.info(`Joining room ID ${data.roomID}`, "AUTH");
                conn.user.joinRoom(server.rooms[data.roomID]);
            }
            Logger.info(`${conn.user.name} successfully authenticated`, "AUTH");
            conn.socket.emit("auth-ok", {username: conn.user.name,
                token: conn.user.token, roomID: conn.user.room.id,
                users: server.getUserList(conn.user.room)});
        });
    }

    registerDisconnectEvent(conn: Connection) : void
    {
        let server = this;
        conn.socket.on("disconnect", () => {
            Logger.info(`Recieved disconnect event from ${conn.user.name}`, "AUTH");
            conn.user.leaveRoom();
            delete server.users[conn.user.token];
        });
    }

    registerMessageEvent(conn: Connection) : void
    {
        
    }

    generateToken(length: number) : string
    {
        let result = "";
        let characters = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
        
        for (var i = 0; i < length; i++)
            result += characters.charAt(Math.floor(Math.random() * characters.length));
        return result;
    }
}

export default GameServer;