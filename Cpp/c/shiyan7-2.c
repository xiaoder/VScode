#include <stdio.h>
void Mystrcat(char *p,char *q);
int main ()
{
    char aa[80];
    char bb[80];
    gets(aa);
    gets(bb);
    Mystrcat(aa,bb);
    puts(aa);
    return 0;
}

void Mystrcat(char *p,char *q)
{
    while(*p)
    p++;
    while(*q)
    {
        *p = *q;
        p++;
        q++;
    }
}