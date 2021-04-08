#include <iostream>
#include <string>
using namespace std;
class Songer
{
    private:
    string Name;
    int Fans_count;
    static int Count;
    public:
    Songer(string name = "?",int fans_count = 0);
    Songer(Songer & m);
    ~Songer();
    void Set(int x);
    Songer operator + (int x);
    bool operator > (Songer & t);
    friend bool operator == (Songer & p, Songer & q);
    Songer & operator ++();
    friend Songer & operator ++(Songer & t,int);
    friend ostream & operator << (ostream & p, Songer & q);
};

int Songer :: Count = 0;
bool operator == (Songer & p, Songer & q)
{
    if(p.Fans_count == q.Fans_count)
    {
        return true;
    }
    return false;
}
Songer & operator ++(Songer & t,int)
{
    static Songer temp(t);
    ++t;
    return temp;
}
// int main()
// {
//     Songer s1("张三",100), s2("李四",120), s3("钟小五");
//     cout << s1 << s2 << s3 << endl;
//     if(s1 > s2)
//     {
//         cout << s1;
//     }
//     else if (s1 == s2)
//     {
//         cout << "s1和s2粉丝数相同" << endl;
//     }
//     else
//     {
//         cout << s2;
//     }
//     s1 = s1 + 20;
//     if(s1 > s2)
//     {
//         cout << s1;
//     }
//     else if (s1 == s2)
//     {
//         cout << "s1和s2粉丝数相同" << endl;
//     }
//     else
//     {
//         cout << s2;
//     }
//     cout << (++s3);
//     cout << (s3++);
//     return 0;
// }
Songer :: Songer(string name, int fans_count)
{
    Name = name;
    Fans_count = fans_count;
    Count++;
}
Songer :: Songer(Songer & m)
{
    Name = m.Name;
    Fans_count = m.Fans_count;
    Count++;
}
Songer :: ~Songer ()
{
    Count--;
    cout << "Songer类析构函数被调用" << endl;
}
void Songer :: Set(int x)
{
    Fans_count = x;
}

Songer Songer :: operator + (int x)
{
    return {Name,Fans_count + x};
}
bool Songer :: operator > (Songer & t)
{
    if(Fans_count > t.Fans_count)
    {
        return true;
    }
    return false;
}
Songer & Songer :: operator ++ ()
{
    Fans_count += 10;
    return *this;
}
ostream & operator << (ostream & p, Songer & q)
{
    p << "姓名:" << q.Name << endl << "粉丝数:" << q.Fans_count << endl;
    return p;
}
