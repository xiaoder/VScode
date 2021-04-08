#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define f(x) (x * x + 1)
float suiji(int m,int n)
{
    return (rand()/(RAND_MAX + 1.0)) * (n - m) + m;
}

int main()
{
    srand(time(NULL));
    long int a, b, d, n, m = 0;
    float x, y;
    printf("请输入n:\n");
    scanf("%d", &n);
    printf("请输入大于0的a,b:\n");
    scanf("%ld%ld", &a, &b);
    d = f(b);
    for (long int i = 0; i < n; i++)
    {
        x = suiji(a, b);
        y = suiji(0, d);
        if(y <= f(x))
        {
            m++;
        }
    }
    printf("f(x)的定积分=%f", (1.0 * m * (b - a) * d/ n));
    return 0;
}