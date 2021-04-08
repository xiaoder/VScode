#include <iostream>
#include <string>
using namespace std;
class Date
{
    private:
    int Year;
    int Month;
    int Day;
    public:
    Date(int year = 0, int month = 0, int day = 0);
    Date(Date & m);
    ~Date();
    void Change(int year, int month,int day);
    void Show();

};
Date :: Date(int year, int month, int day)
{
    Year =year;
    Month = month;
    Day = day;
}
Date :: Date(Date & m)
{
    Year = m.Year;
    Month = m.Month;
    Day = m.Day;
}
Date ::~Date()
{
    cout << "Date类析构函数被调用" << endl;
}
void Date :: Change(int year, int month, int day)
{
    Year = year;
    Month = month;
    Day = day;
}
void Date :: Show()
{
    cout << Year << "年" << Month << "月" << Day << "日" << endl;
}
class People
{
    private:
    int Num;
    string Name;
    string Id;
    Date Birth;
    public:
    People();
    People(int year, int month,int day,int num, string name, string id);
    People(People & m);
    ~People();
    void Key_in(int year, int month,int day,int num,string name, string id);
    void Show();
};
People :: People()
:Birth()
{
    Num = 0;
    Name = "?";
    Id = "?";
}
People :: People(int year, int month,int day,int num, string name, string id)
:Birth(year,month,day)
{
    Num = num;
    Name = name;
    Id = id;
}
People :: People(People & m)
:Birth(m.Birth)
{
    Num = m.Num;
    Name = m.Name;
    Id = m.Id;
}
People :: ~People()
{
    cout << "People类析构函数被调用" << endl;
}
void People :: Key_in(int year, int month,int day,int num,string name, string id)
{
    Birth.Change(year,month,day);
    Num = num;
    Name = name;
    Id = id;
}
void People :: Show()
{
    cout << "姓名:" << Name << endl;
    cout << "编号:" << Num << endl;
    cout << "id:" << Id << endl;
    cout << "日期:";
    Birth.Show();
}
int main()
{
    People a(2020,4,1,20190001,"张三","1111111"), b;
    a.Show();
    b.Show();
    b.Key_in(2020,4,2,20100002,"李四","2222222");
    a.Show();
    b.Show();
    return 0;
}