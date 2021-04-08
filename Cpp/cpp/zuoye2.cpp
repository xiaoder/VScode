#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
class Set
{
    private:
    int date[100];
    int len;
    bool Exist(int x);
    public:
    Set();
    Set(int n);
    Set(Set & m);
    ~Set();
    bool Add(int x);
    bool Delete(int x);
    void Show();
    Set Intersection(Set m);
    Set Union_Set(Set m);
    Set Different_Set(Set m);
    bool Equal(Set m);
    bool Include(Set m);
    bool IsEmpty();
    int Size();
    void Clear();
};
void Menu()
{
    cout << "1-��������s1,s2,s3" << endl;
    cout << "2-��s1�����һ��Ԫ��" << endl;
    cout << "3-�Ӽ���s3��ɾ��һ��Ԫ��" << endl;
    cout << "4-����s1��s2�Ľ���" << endl;
    cout << "4-����s1��s2�Ľ���" << endl;
    cout << "5-����s1��s2�Ĳ���" << endl;
    cout << "6-����s1��s2�Ĳ" << endl;
    cout << "7-��ʾָ���ļ���" << endl;
    cout << "8-�ж�s1��s2�Ƿ����" << endl;
    cout << "9-�ж�s1�Ƿ����s2" << endl;
    cout << "10-���ָ���ļ���" << endl;
    cout << "11-�ж�ָ���ļ����Ƿ�Ϊ��" << endl;
    cout << "12-Quit program" << endl;
}
int main()
{
    srand(time(NULL));
    Set result;
    bool flag = true;
    int t;
    Set s1, s2(5), s3(s2);
    cout << "s1:";
    s1.Show();
    cout << "s2:";
    s2.Show();
    cout << "s3:";
    s3.Show();
    system("pause");
    while(flag)
    {
        system("cls");
        Menu();
        cin >> t;
        switch (t)
        {
            case 1:
            {
                
                break;
            }
            case 2:
            {
                int x = rand() % 100 + 1;
                s1.Add(x);
                cout << "s1:";
                s1.Show();
                break;
            }
            case 3:
            {
                cout << "s3:";
                s3.Show();
                cout << "������Ҫɾ����Ԫ��:";
                int x;
                cin >> x;
                s3.Delete(x);
                cout << "s3:";
                s3.Show();
                break;
            }
            case 4:
            {
                cout << "s1:";
                s1.Show();
                cout << "s2:";
                s2.Show();
                result = s1.Intersection(s2);
                cout << "s1��s2�Ľ���Ϊ:";
                result.Show();
                break;
            }
            case 5:
            {
                cout << "s1:";
                s1.Show();
                cout << "s2:";
                s2.Show();
                result = s1.Union_Set(s2);
                cout << "s1��s2�Ĳ���Ϊ:";
                result.Show();
                break;
            }
            case 6:
            {
                cout << "s1:";
                s1.Show();
                cout << "s2:";
                s2.Show();
                result = s1.Different_Set(s2);
                cout << "s1��s2�ĲΪ:";
                result.Show();
                break;
            }
            case 7:
            {
                cout << "������Ҫ��ʾ�ļ���:";
                char str[5];
                cin >> str;
                if(str[1] == '1')
                {
                    cout << "s1:";
                    s1.Show();
                }
                else if(str[1] == '2')
                {
                    cout << "s2:";
                    s2.Show();
                }
                else if(str[1] == '3')
                {
                    cout << "s3:";
                    s3.Show();
                }
                else
                {
                    cout << "��������" << endl;
                }
                break;
            }
            case 8:
            {
                if(s1.Equal(s2))
                {
                    cout << "s1��s2���" << endl;
                }
                else
                {
                    cout << "s1��s2�����" << endl;
                }
                break;
            }
            case 9:
            {
                if(s1.Include(s2))
                {
                    cout << "s1����s2" << endl;
                }
                else
                {
                    cout << "s1������s2" << endl;
                }
                break;
            }
            case 10:
            {
                cout << "������Ҫ��յļ���:";
                char str[5];
                cin >> str;
                if(str[1] == '1')
                {
                    s1.Clear();
                }
                else if(str[1] == '2')
                {
                    s2.Clear();
                }
                else if(str[1] == '3')
                {
                    s3.Clear();
                }
                else
                {
                    cout << "��������" << endl;
                }
                break;
            }
            case 11:
            {
                cout << "������Ҫ�ж��Ƿ�Ϊ�յļ���:";
                char str[5];
                cin >> str;
                if(str[1] == '1')
                {
                    if(s1.IsEmpty())
                    {
                        cout << "s1Ϊ��" << endl;
                    }
                    else
                    {
                        cout << "s1��Ϊ��" << endl;
                    }
                    
                }
                else if(str[1] == '2')
                {
                    if(s2.IsEmpty())
                    {
                        cout << "s2Ϊ��" << endl;
                    }
                    else
                    {
                        cout << "s2��Ϊ��" << endl;
                    }
                }
                else if(str[1] == '3')
                {
                    if(s3.IsEmpty())
                    {
                        cout << "s3Ϊ��" << endl;
                    }
                    else
                    {
                        cout << "s3��Ϊ��" << endl;
                    }
                }
                else
                {
                    cout << "��������" << endl;
                }
                break;
            }
            case 12:
            {
                flag = false;
                break;
            }
            default :
            {
                cout << "���������" << endl;
            }
        }
        system("pause");
    }
}
Set :: Set()
{
    len = 0;
}
Set :: Set(int n)
{
    len = 0;
    for (int i = 0; i < n; i++)
    {
        while(true)
        {
            int x = rand() % 100 + 1;
            if(Add(x))
            {
                break;
            }
        }
    }
}
Set :: Set(Set & m)
{
    len = m.len;
    for (int i = 0; i < len; i++)
    {
        date[i] = m.date[i];
    }
}
Set :: ~Set()
{
    cout << "��������������" << endl;
}
bool Set :: Exist(int x)
{
    for(int i = 0; i < len; i++)
    {
        if(x == date[i])
        {
            return true;
        }
    }
    return false;
}
bool Set :: Add(int x)
{
    if(Exist(x))
    {
        return false;
    }
    else
    {
        date[len] = x;
        len++;
        return true;
    }
}
bool Set :: Delete(int x)
{
    for(int i = 0; i < len; i++)
    {
        if(x == date[i])
        {
            len--;
            for(int j = i; j < len; j++)
            {
                date[j] = date[j+1];
            }
            return true;
        }
    }
    return false;
}
void Set :: Show()
{
    for(int i = 0; i < len; i++)
    {
        cout << date[i] << " ";
    }
    cout << endl;
}
Set Set :: Intersection(Set m)
{
    Set result;
    for(int i = 0; i < len; i++)
    {
        if(m.Exist(date[i]))
        {
            result.Add(date[i]);
        }
    }
    return result;
}
Set Set :: Union_Set(Set m)
{
    Set result;
    for(int i = 0; i < len; i++)
    {
        result.Add(date[i]);
    }
    for(int i = 0; i < m.len; i++)
    {
        result.Add(m.date[i]);
    }
    return result;
}
Set Set :: Different_Set(Set m)
{
    Set result;
    for(int i = 0; i < len; i++)
    {
        if(!m.Exist(date[i]))
        {
            result.Add(date[i]);
        }
    }
    for(int i = 0; i < m.len; i++)
    {
        if(!Exist(m.date[i]))
        {
            result.Add(m.date[i]);
        }
    }
    return result;
}
bool Set :: Equal(Set m)
{
    if(len != m.len)
    {
        return false;
    }
    for(int i = 0; i < len; i++)
    {
        if(!m.Exist(date[i]))
        {
            return false;
        }
    }
    return true;
}
bool Set :: Include(Set m)
{
    for(int i = 0; i < m.len; i++)
    {
        if(!Exist(m.date[i]))
        {
            return false;
        }
    }
    return true;
}
bool Set :: IsEmpty()
{
    if(len == 0)
    {
        return true;
    }
    return false;
}
int Set :: Size()
{
    return len;
}
void Set :: Clear()
{
    len = 0;
    cout << "�ü��������" << endl;
}
