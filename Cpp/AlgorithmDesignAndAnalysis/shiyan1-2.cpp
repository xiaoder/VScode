#include <iostream>
#include <algorithm>
using namespace std;

typedef struct result
{
    int max; //众数
    int num; //重数
} result;

result max(int aa[], int x);
int main()
{
    cout << "请输入数据个数:";
    int n;
    cin >> n;
    cout << "请输入数据:";
    int aa[n];
    for (int i = 0; i < n; i++)
    {
        cin >> aa[i];
    }
    //1 2 2 2 5 7 7
    //int aa[] = {1, 2, 2, 7, 2, 7, 5}; //数据
    sort(aa, aa + n); //排序预处理
    result r;         //存放结果的结构体
    r = max(aa, n);   //调用递归函数
    cout << r.max << " " << r.num;
    return 0;
}

result max(int aa[], int x)
{
    if (x == 1) //函数出口，只有一个数直接返回
    {
        result r;
        r = {aa[0], 1};
        return r;
    }
    int t = x / 2;                     //找到划分的中间位置t
    result left = max(aa, t);          //递归求出左边众数重数
    result right = max(aa + t, x - t); //递归求出右边众数重数
    result mid;
    if (aa[t] == aa[t - 1]) //从中间向左右两边找中间位置数的重数
    {
        int t0 = t, t1 = t - 1;
        while (aa[++t0] == aa[t])
            ;
        while (aa[--t1] == aa[t])
            ;
        mid = {aa[t], t0 - t1 - 1};
    }
    else
    {
        mid = {aa[t], 1};
    }
    if (left.num < right.num) //返回左中右重数最大的数
    {
        return mid.num > right.num ? mid : right;
    }
    else
    {
        return mid.num > left.num ? mid : left;
    }
}