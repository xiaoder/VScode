#include <stdio.h>
int main()
{
    int d[1000];
    int p, n;
    d[0] = 5;
    printf("请输入p,n:\n");
    scanf("%d%d", &p, &n);
    for (int i = 1; i < n; i++)
    {
        d[i] = d[i - 1] << 1;
        if(d[i]>p)
        {
            d[i] &= p;
            d[i] ^= 3;
        }
    }
    printf("产生的伪随机数序列如下:\n");
    for (int i = 0; i < n; i++)
    {
        if(i && i % 8 == 0)
            putchar('\n');
        printf("%3d  ", d[i]);
    }
    putchar('\n');
    return 0;
}