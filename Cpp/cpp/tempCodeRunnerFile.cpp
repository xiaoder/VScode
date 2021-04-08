int operator < (const User & p)
    {
        if(username < p.username)
        return 1;
        return 0;
    }
    int operator > (const User & p)
    {
        if(username > p.username)
        return 1;
        return 0;
    }