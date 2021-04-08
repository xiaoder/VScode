#include <iostream>
using namespace std;
typedef struct array
{
    int *head;
    int length;
}array;
int creatarrray(array &t)
{
    t.head = new int[100];
    t.head[0] = 1;
    t.head[1] = 3;
    t.head[2] = 5;
    t.head[3] = 7;
    t.head[4] = 9;
    t.length = 5;
}
int insert(array &t, int x)
{
    int i;
    for (i = 0; i < t.length; i++)
    {
        if(t.head[i] > x)
        {
            for (int j = t.length; j > i; j--)
            {
                t.head[j] = t.head[j-1];
            }
            t.head[i] = x;
            break;
        }
    }
    if(i == t.length)
    {
        t.head[t.length] = x;
    }
    t.length++;
}
int youyi(array &t, int k)
{
    int x;
    k = k % t.length;
    for (int i = 0; i < k; i++)
    {
        x = t.head[t.length-1];
        for (int j = t.length; j > 0; j--)
        {
            t.head[j] = t.head[j-1];
        }
        t.head[0] = x;
    }
}
int reverse(array &t)
{
    int temp;
    for (int i = 0; i < t.length/2; i++)
    {
        temp = t.head[i];
        t.head[i] = t.head[t.length-i-1];
        t.head[t.length-i-1] = temp;
    }
}

int output(array t)
{
    for (int i = 0; i < t.length; i++)
    {
        cout << t.head[i] << " ";
    }
    cout << endl;
}
int main()
{
    int a, x, k;
    array t;
    int flag = 1;
    creatarrray(t);
    while(flag)
    {
        cout << "(1)插入\n(2)循环右移k位\n(3)逆置\n(4)输出\n(5)退出\n";
        cout << "请输入操作序号:";
        cin >> a;
        switch (a)
        {
            case 1:
            {
                cout << "请输入要插入的数:";
                cin >> x;
                insert(t,x);
                break;
            }
            case 2:
            {
                cout << "请输入右移位数:";
                cin >> k;
                youyi(t,k);
                break;
            }
            case 3:
            {
                reverse(t);
                break;
            }
            case 4:
            {
                output(t);
                break;
            }
            case 5:
            {
                delete [] t.head;
                flag = 0;
                break;
            }
        }
    }
    return 0;
}