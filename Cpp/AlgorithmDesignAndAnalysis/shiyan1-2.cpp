#include <iostream>
#include <algorithm>
using namespace std;

typedef struct result
{
    int max; //����
    int num; //����
} result;

result max(int aa[], int x);
int main()
{
    cout << "���������ݸ���:";
    int n;
    cin >> n;
    cout << "����������:";
    int aa[n];
    for (int i = 0; i < n; i++)
    {
        cin >> aa[i];
    }
    //1 2 2 2 5 7 7
    //int aa[] = {1, 2, 2, 7, 2, 7, 5}; //����
    sort(aa, aa + n); //����Ԥ����
    result r;         //��Ž���Ľṹ��
    r = max(aa, n);   //���õݹ麯��
    cout << r.max << " " << r.num;
    return 0;
}

result max(int aa[], int x)
{
    if (x == 1) //�������ڣ�ֻ��һ����ֱ�ӷ���
    {
        result r;
        r = {aa[0], 1};
        return r;
    }
    int t = x / 2;                     //�ҵ����ֵ��м�λ��t
    result left = max(aa, t);          //�ݹ���������������
    result right = max(aa + t, x - t); //�ݹ�����ұ���������
    result mid;
    if (aa[t] == aa[t - 1]) //���м��������������м�λ����������
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
    if (left.num < right.num) //��������������������
    {
        return mid.num > right.num ? mid : right;
    }
    else
    {
        return mid.num > left.num ? mid : left;
    }
}