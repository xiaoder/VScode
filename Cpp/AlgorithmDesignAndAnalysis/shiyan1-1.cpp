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
    cout << "���������ݸ���:";
    int n;
    cin >> n;
    cout << "����������:";
    int aa[n];
    for (int i = 0; i < n; i++)
    {
        cin >> aa[i];
    }
    //int aa[] = {-2, 11, -4, 13, -5, -2}; //����
    result r;                //��Ž���Ľṹ��
    r = maxSubstring(aa, n); //���õݹ麯��
    cout << r.begin + 1 << " " << r.end + 1 << " " << r.max;
    return 0;
}

result maxSubstring(int aa[], int x)
{
    if (x == 1) //�������ڣ�ֻ��һ����ֱ�ӷ���
    {
        result r;
        r.begin = 0;
        r.end = 0;
        r.max = aa[0];
        return r;
    }
    int t = x / 2;                              //�ҵ����ֵ��м�λ��t
    result left = maxSubstring(aa, t);          //�ݹ�����������Ӷκ�
    result right = maxSubstring(aa + t, x - t); //�ݹ�����ұ�����ֶκ�
    right.begin += t;                           //�ұߵõ���ֵ�Ǵ�t��ʼ�ģ���ʵֵҪ��t
    right.end += t;
    int rm, lm, temp;
    int ri, li;
    ri = t;
    li = t;
    rm = 0;
    lm = 0;
    temp = 0;
    for (int i = t; i < x; i++) //��t��ʼ����������Ӷ�
    {
        temp += aa[i]; //��¼�Ҳ��Ӷ�ֵ
        if (temp > rm)
        {
            rm = temp; //��¼�Ҳ�����Ӷ�ֵ
            ri = i;    //��¼�Ҳ�����Ӷ��±�
        }
    }
    temp = 0;
    for (int i = t - 1; i >= 0; i--) //��t��ʼ����������Ӷ�
    {
        temp += aa[i]; //��¼����Ӷ�ֵ
        if (temp > lm)
        {
            lm = temp; //��¼�������Ӷ�ֵ
            li = i;    //��¼�������Ӷ��±�
        }
    }
    temp = lm + rm;
    result mid = {li, ri, temp};
    if (left.max < right.max) //���������������������Ӷκ�
    {
        return mid.max > right.max ? mid : right;
    }
    else
    {
        return mid.max > left.max ? mid : left;
    }
}