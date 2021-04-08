#include <stdio.h>
int aa[101], n;//����ȫ�ֱ�����������������Ҫ���Ӻ�����ʹ��

void quicksort (int left, int right)
{
    int i, j, t, temp;
    if (left > right)
        return;
    
    temp = aa[left];//temp�д�ľ��ǻ�׼��
    i = left;
    j = right;
    while (i != j)
    {
        while (aa[j] >= temp && i < j)//����������
            j--;
        while (aa[i] <= temp && i < j)//����������
            i++;
        if (i < j)//���ڱ�i���ڱ�jû����ʱ�������������������е�λ��
        {
            t = aa[i];
            aa[i] = aa[j];
            aa[j] = t;
        }
        
    }
    aa[left] = aa[i];//����׼����λ
    aa[i] = temp;
    quicksort (left,i - 1);//����������ߵģ�������һ���ݹ�Ĺ���
    quicksort (i + 1,right);//���������ұߵģ�������һ���ݹ�Ĺ���
    return;
}

int main()
{
    int i, j;
    scanf("%d",&n);
    for ( i = 0; i < n; i++)
        scanf("%d",&aa[i]);

    quicksort(0,n-1);
    for ( i = 0; i < n; i++)
    printf("%d ",aa[i]);
    return 0;
}