#include <stdio.h>
int aa[101], n;//定义全局变量，这两个变量需要在子函数中使用

void quicksort (int left, int right)
{
    int i, j, t, temp;
    if (left > right)
        return;
    
    temp = aa[left];//temp中存的就是基准数
    i = left;
    j = right;
    while (i != j)
    {
        while (aa[j] >= temp && i < j)//从右往左找
            j--;
        while (aa[i] <= temp && i < j)//从左往右找
            i++;
        if (i < j)//当哨兵i和哨兵j没相遇时，交换两个数在数组中的位置
        {
            t = aa[i];
            aa[i] = aa[j];
            aa[j] = t;
        }
        
    }
    aa[left] = aa[i];//将基准数归位
    aa[i] = temp;
    quicksort (left,i - 1);//继续处理左边的，这里是一个递归的过程
    quicksort (i + 1,right);//继续处理右边的，这里是一个递归的过程
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