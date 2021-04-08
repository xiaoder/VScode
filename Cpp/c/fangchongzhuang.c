#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
int RA (int Ac)
{
    if (Ac)
    {
        return Ac;
    }
    else
    {
        return rand() % 2;
    }
    
}
int RB (int Bc)
{
    if (Bc)
    {
        return Bc;
    }
    else
    {
        return rand() % 2;
    }
    
}
int RD (int Dc)
{
    if (Dc)
    {
        return Dc;
    }
    else
    {
        return rand() % 2;
    }
    
}
int main ()
{
    char Reader[10];
    char ch;
    int Ac, Bc, Dc;
    int n = 3;
    int count;
    Ac = 0;
    Bc = 0;
    Dc = 0;
    srand(time(NULL));
    printf("A\tB\tD\t\n");
    while (n)
    {
        ch = ' ';
        count = 0;
        if (!Ac)
        {
            Ac = RA(Ac);
        }
        if (!Bc)
        {
            Bc = RB(Bc);
        }
        if (!Dc)
        {
            Dc = RD(Dc);
        }
        if (!Ac)
        {
            count++;
            ch = 'A';
        }
        if (!Bc)
        {
            count++;
            ch = 'B';
        }
        if (!Dc)
        {
            count++;
            ch = 'D';
        }
        if(Ac >= 0)
        {
            printf("%d\t",Ac);
        }
        else
        {
            printf("¾²Ä¬\t");
        }
        if(Bc >= 0)
        {
            printf("%d\t",Bc);
        }
        else
        {
            printf("¾²Ä¬\t");
        }
        if(Dc >= 0)
        {
            printf("%d\t",Dc);
        }
        else
        {
            printf("¾²Ä¬\t");
        }
        if (count == 1)
        {
            n--;
            strcpy(Reader,"SUCCESS");
            printf("%s\t\t%c±êÇ©ALOHA\n",Reader,ch);
            Ac--;
            Bc--;
            Dc--;
        }
        else if (count == 0)
        {
            strcpy (Reader,"RESET");
            puts(Reader);
            if (Ac > 0)
            {
                Ac--;
            }
            if (Bc > 0)
            {
                Bc--;
            }
            if (Dc > 0)
            {
                Dc--;
            }
        }
        else
        {
            strcpy(Reader,"FAIL");
            puts(Reader);
            if (Ac > 0)
            {
                Ac++;
            }
            if (Bc > 0)
            {
                Bc++;
            }
            if (Dc > 0)
            {
                Dc++;
            }
        }
    }
    return 0;
}