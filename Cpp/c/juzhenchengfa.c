#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int *a, *b, *c, p, q, i, j, k, m, n;
    printf("请输入第一个矩阵的行列数:");
    scanf("%d%d",&m,&n);
    a = (int *)malloc (m * n * sizeof(int));
    printf("请输入第一个矩阵\n");
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d",a+i*n+j);
        }
    }
    printf("请输入第二个矩阵的行列数:");
    scanf("%d%d",&p,&q);
    b = (int *)malloc (p * q * sizeof(int));
    printf("请输入第二个矩阵\n");
    for (i = 0; i < p; i++)
    {
        for (j = 0; j < q; j++)
        {
            scanf("%d",b+i*q+j);
        }
    }
    if(n != p)
    {
        free(a);
        free(b);
        printf("无法相乘\n");
    }
    else
    {
        c = (int *)malloc (m * q * sizeof(int));
        memset(c,0, m * q * sizeof(int));
        for (i = 0; i < m; i++)
        {
            for (j = 0; j < q; j++)
            {
                for (k = 0; k < n; k++)
                {
                    *(c+i*q+j) += (*(a+i*n+k)) * (*(b+k*q+j));
                }
            }
        }
        free(a);
        free(b);
        printf("结果为\n");
         for (i = 0; i < m; i++)
        {
            for (j = 0; j < q; j++)
            {
                printf("%d ",*(c+i*q+j));
            }
            printf("\n");
        }
        free(c);
    }
}
