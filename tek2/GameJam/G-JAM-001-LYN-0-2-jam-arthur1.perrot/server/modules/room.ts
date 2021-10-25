import Logger from "../util/logger";
import GameServer from "./gameserver";
import User from "./user";

class Room
{
    id: string;
    owner: User;
    users: {[key: string]: User} = {};

    constructor(id: string, owner: User)
    {
        this.id = id;
        this.owner = owner;
        this.users = {};
        this.users[owner.id] = owner;
    }

    addUser(user : User) : void
    {
        this.users[user.id] = user;
        for (const [key, value] of Object.entries(this.users)) {
            if (key !== user.id) {
                user.socket.emit("user-join", {id: user.id, username: user.name,
                    score: user.score});
            }
        }
    }
    
    removeUser(id : string) : void
    {
        if (id in this.users) {
            Logger.info(`User ${this.users[id].name} left the room`, `ROOM ${this.id}`);
            delete this.users[id];
        }
        if (Object.keys(this.users).length === 0) {
            delete GameServer.instance.rooms[this.id];
            return;
        }
        if (this.owner.id === id) {
            this.owner = Object.entries(this.users)[0][1];
            for (const [id, user] of Object.entries(this.users)) {
                user.socket.emit("user-leave", id);
            }
        }
    }
}

export default Room;