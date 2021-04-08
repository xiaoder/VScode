#include <iostream>
using namespace std;

typedef struct result
{
    int begin;
    int end;
    int max;
} result;

result maxSubstring(int aa[], int x);
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
    //int aa[] = {-2, 11, -4, 13, -5, -2}; //数据
    result r;                //存放结果的结构体
    r = maxSubstring(aa, n); //调用递归函数
    cout << r.begin + 1 << " " << r.end + 1 << " " << r.max;
    return 0;
}

result maxSubstring(int aa[], int x)
{
    if (x == 1) //函数出口，只有一个数直接返回
    {
        result r;
        r.begin = 0;
        r.end = 0;
        r.max = aa[0];
        return r;
    }
    int t = x / 2;                              //找到划分的中间位置t
    result left = maxSubstring(aa, t);          //递归求出左边最大子段和
    result right = maxSubstring(aa + t, x - t); //递归求出右边最大字段和
    right.begin += t;                           //右边得到的值是从t开始的，真实值要加t
    right.end += t;
    int rm, lm, temp;
    int ri, li;
    ri = t;
    li = t;
    rm = 0;
    lm = 0;
    temp = 0;
    for (int i = t; i < x; i++) //从t开始向右找最大子段
    {
        temp += aa[i]; //记录右侧子段值
        if (temp > rm)
        {
            rm = temp; //记录右侧最大子段值
            ri = i;    //记录右侧最大子段下标
        }
    }
    temp = 0;
    for (int i = t - 1; i >= 0; i--) //从t开始向左找最大子段
    {
        temp += aa[i]; //记录左侧子段值
        if (temp > lm)
        {
            lm = temp; //记录左侧最大子段值
            li = i;    //记录左侧最大子段下标
        }
    }
    temp = lm + rm;
    result mid = {li, ri, temp};
    if (left.max < right.max) //返回左中右三个中最大的子段和
    {
        return mid.max > right.max ? mid : right;
    }
    else
    {
        return mid.max > left.max ? mid : left;
    }
}