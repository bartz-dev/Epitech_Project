import { Socket } from "socket.io"
import Logger from "../util/logger";
import Connection from "./connection";
import GameServer from "./gameserver";
import Room from "./room";

class User
{
    id: string;
    token: string;
    name: string;
    socket: Socket;
    ownedRoom: Room;
    room: Room;
    score: number;
    
    constructor(id: string, token: string, name: string, socket: Socket)
    {
        this.id = id;
        this.token = token;
        this.name = name;
        this.socket = socket;
        this.ownedRoom = undefined;
        this.score = 0;
    }

    static create(username : string, conn : Connection)
    {
        let server = GameServer.instance;
        let token : string;
        let tokenExists : boolean;
        do {
            tokenExists = false;
            token = "JAM-" + server.generateToken(20);
            for (const [key, value] of Object.entries(server.users)) {
                tokenExists = tokenExists ? tokenExists : value.token === token;
            }
        } while (tokenExists)
        let idExists : boolean;
        let id : string;
        do {
            idExists = false;
            id = server.generateToken(6);
            for (const [key, value] of Object.entries(server.users)) {
                idExists = idExists ? idExists : value.id === id;
            }
        } while (idExists)
        return new User(id, token, username, conn.socket);
    }

    static authenticate(data : {username: string, token: string, roomID: string},
        conn : Connection) {
        if (data.token === undefined || !(data.token in GameServer.instance.users)) {
            let user = User.create(data.username, conn);
            GameServer.instance.users[user.token] = user;
            conn.user = user;
            Logger.info(`Sending back token ${user.token}`, "AUTH");
        } else {
            conn.user = GameServer.instance.users[data.token];
            conn.user.socket = conn.socket;
            Logger.info(`Token ${data.token} already exists`, "AUTH");
        }
    }
    
    createRoom(roomID: string) : Room
    {
        this.ownedRoom = new Room(roomID, this);
        this.joinRoom(this.ownedRoom);
        return this.ownedRoom;
    }

    joinRoom(room: Room) : void
    {
        this.room = room;
        this.room.addUser(this);
    }

    leaveRoom() : void
    {
        this.room.removeUser(this.id);
        this.room = undefined;
    }
}

export default User;