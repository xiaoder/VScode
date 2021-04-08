#include <stdio.h>
int Mystrcmp(char *p,char *q);
int main ()
{
    char aa[80];
    char bb[80];
    gets(aa);
    gets(bb);
    if(Mystrcmp(aa,bb)>0)
    printf("a>b\n");
    else if(Mystrcmp(aa,bb)<0)
    printf("a<b\n");
    else
    printf("a=b\n");
    return 0;
}

int Mystrcmp(char *p,char *q)
{
    while(*p && *p == *q)
    {
        p++;
        q++;
    }
    return *p - *q;
}