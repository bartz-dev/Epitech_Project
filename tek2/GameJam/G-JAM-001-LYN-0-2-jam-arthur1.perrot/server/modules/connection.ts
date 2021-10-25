import { Socket } from "socket.io";
import User from "./user";

class Connection
{
    user: User;
    socket: Socket;

    constructor(user: User, socket: Socket)
    {
        this.user = user;
        this.socket = socket;
    }
}

export default Connection;