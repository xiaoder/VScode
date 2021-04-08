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
    cout << "1-创建集合s1,s2,s3" << endl;
    cout << "2-向s1中添加一个元素" << endl;
    cout << "3-从集合s3中删除一个元素" << endl;
    cout << "4-计算s1和s2的交集" << endl;
    cout << "4-计算s1和s2的交集" << endl;
    cout << "5-计算s1和s2的并集" << endl;
    cout << "6-计算s1和s2的差集" << endl;
    cout << "7-显示指定的集合" << endl;
    cout << "8-判断s1和s2是否相等" << endl;
    cout << "9-判断s1是否包含s2" << endl;
    cout << "10-清空指定的集合" << endl;
    cout << "11-判断指定的集合是否为空" << endl;
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
                cout << "请输入要删除的元素:";
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
                cout << "s1和s2的交集为:";
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
                cout << "s1和s2的并集为:";
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
                cout << "s1和s2的差集为:";
                result.Show();
                break;
            }
            case 7:
            {
                cout << "请输入要显示的集合:";
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
                    cout << "输入有误" << endl;
                }
                break;
            }
            case 8:
            {
                if(s1.Equal(s2))
                {
                    cout << "s1和s2相等" << endl;
                }
                else
                {
                    cout << "s1和s2不相等" << endl;
                }
                break;
            }
            case 9:
            {
                if(s1.Include(s2))
                {
                    cout << "s1包含s2" << endl;
                }
                else
                {
                    cout << "s1不包含s2" << endl;
                }
                break;
            }
            case 10:
            {
                cout << "请输入要清空的集合:";
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
                    cout << "输入有误" << endl;
                }
                break;
            }
            case 11:
            {
                cout << "请输入要判断是否为空的集合:";
                char str[5];
                cin >> str;
                if(str[1] == '1')
                {
                    if(s1.IsEmpty())
                    {
                        cout << "s1为空" << endl;
                    }
                    else
                    {
                        cout << "s1不为空" << endl;
                    }
                    
                }
                else if(str[1] == '2')
                {
                    if(s2.IsEmpty())
                    {
                        cout << "s2为空" << endl;
                    }
                    else
                    {
                        cout << "s2不为空" << endl;
                    }
                }
                else if(str[1] == '3')
                {
                    if(s3.IsEmpty())
                    {
                        cout << "s3为空" << endl;
                    }
                    else
                    {
                        cout << "s3不为空" << endl;
                    }
                }
                else
                {
                    cout << "输入有误" << endl;
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
                cout << "请从新输入" << endl;
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
    cout << "析构函数被调用" << endl;
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
    cout << "该集合已清空" << endl;
}
