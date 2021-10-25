class Logger
{
    static info(message: String, module: String = undefined)
    {
        if (module !== undefined)
            console.info(`[SRV][INFO][${module}] ${message}`)
        else
            console.info(`[SRV][INFO] ${message}`);
    }
    static warn(message: String, module: String = undefined)
    {
        if (module !== undefined)
            console.warn(`[SRV][WARN][${module}] ${message}`)
        else
            console.warn(`[SRV][WARN] ${message}`);
    }
    static error(message: String, module: String = undefined)
    {
        if (module !== undefined)
            console.error(`[SRV][ERR][${module}] ${message}`)
        else
            console.error(`[SRV][ERR] ${message}`);
    }
}

export default Logger;