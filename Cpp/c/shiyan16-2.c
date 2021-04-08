#include <stdio.h>
#include <stdlib.h>
#include <time.h>
float suiji(int m,int n)
{
    return (rand()/(RAND_MAX + 1.0)) * (n - m) + m;
}
int main()
{
    srand(time(NULL));
    long int n, k = 0;
    float x, y;
    printf("请输入要投掷的点数:");
    scanf("%ld", &n);
    for (long int i = 0; i < n; i++)
    {
        x = suiji(-1, 1);
        y = suiji(-1, 1);
        if(x * x + y * y <= 1)
        {
            k++;
        }
    }
    printf("pi:%f", 4.0 * k / n);
    return 0;
}