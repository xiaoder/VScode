#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int *a, *b, *c, p, q, i, j, k, m, n;
    printf("�������һ�������������:");
    scanf("%d%d",&m,&n);
    a = (int *)malloc (m * n * sizeof(int));
    printf("�������һ������\n");
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d",a+i*n+j);
        }
    }
    printf("������ڶ��������������:");
    scanf("%d%d",&p,&q);
    b = (int *)malloc (p * q * sizeof(int));
    printf("������ڶ�������\n");
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
        printf("�޷����\n");
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
        printf("���Ϊ\n");
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
