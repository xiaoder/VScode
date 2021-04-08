#include <stdio.h>
#include <string.h>
int main ()
{
    char aa[10][20];
    char *bb[10];
    char *t;
    int i, j, k;
    for (i = 0; i < 10; i++)
    {
        gets(aa[i]);
        bb[i] = aa[i];
    }
    for (i = 0; i < 9; i++)
    {
        k = i;
        for (j = i + 1; j < 10; j++)
        {
            if (strcmp(bb[i],bb[j])>0)
            {
                t = bb[i];
                bb[i] = bb[j];
                bb[j] = t;
            }
        }
    }
    for (i = 0; i < 10; i++)
    {
        puts(bb[i]);
    }
}