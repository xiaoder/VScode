#include <iostream> 
#include <string>
using namespace std;
class Preson
{
    protected:
    string Name;
    bool Sex;
    int Age;
    public:
    Preson();
    Preson(string name, bool sex, int age);
    Preson(Preson & t);
    void Set(string name, bool sex, int age);
    void Show();
};

class Student : protected Preson
{
    protected:
    string Num;
    string School;
    string Major;
    public:
    Student();
    Student(string name, bool sex, int age, string num, string school, string major);
    Student(Student & t);
    void Set(string name, bool sex, int age, string num, string school, string major);
    void Show();
};

class Graduate : protected Student
{
    protected:
    string Research_Direction;
    public:
    Graduate();
    Graduate(string name, bool sex, int age, string num, string school, string major, string research_direction);
    Graduate(Graduate & t);
    void Set(string name, bool sex, int age, string num, string school, string major, string research_direction);
    void Show();  
};

int main()
{
    Graduate a, b("张三", 1, 20, "20191234", "黑龙江大学", "计算机", "人工智能"), c(b);
    a.Show();
    b.Show();
    c.Show();
    c.Set("李四", 0, 21, "20194321", "黑龙江大学", "软件工程", "大数据");
    c.Show();
}

Preson :: Preson()
{
    Name = "**";
    Sex = false;
    Age = 0;
}
Preson :: Preson(string name, bool sex, int age)
{
    Name = name;
    Sex = sex;
    Age = age;
}
Preson :: Preson(Preson & t)
{
    Name = t.Name;
    Sex = t.Sex;
    Age = t.Age;
}
void Preson :: Set(string name, bool sex, int age)
{
    Name = name;
    Sex = sex;
    Age = age;
}
void Preson :: Show()
{
    cout << "姓名:" << Name << endl;
    if(Sex)
    {
        cout << "性别:" << "男" << endl;
    }
    else
    {
        cout << "性别:" << "女" << endl;
    }
    
    cout << "年龄:" << Age << endl;
}

Student :: Student()
{
    Num = "**";
    School = "**";
    Major = "**";
}
Student :: Student(string name, bool sex, int age, string num, string school, string major)
:Preson(name, sex, age)
{
    Num = num;
    School = school;
    Major = major;
}
Student :: Student(Student & t)
:Preson(t)
{
    Num = t.Num;
    School = t.School;
    Major = t.Major;    
}
void Student :: Set(string name, bool sex, int age, string num, string school, string major)
{
    Preson :: Set(name, sex, age);
    Num = num;
    School = school;
    Major = major;
}
void Student :: Show()
{
    Preson :: Show();
    cout << "学号:" << Num << endl;
    cout << "学校:" << School << endl;
    cout << "专业:" << Major << endl;
}

Graduate :: Graduate()
{
    Research_Direction = "**";
}
Graduate :: Graduate(string name, bool sex, int age, string num, string school, string major, string research_direction)
:Student(name, sex, age, num, school, major)
{
    Research_Direction = research_direction;
}
Graduate :: Graduate(Graduate & t)
:Student(t)
{
    Research_Direction = t.Research_Direction;
}
void Graduate :: Set(string name, bool sex, int age, string num, string school, string major, string research_direction)
{
    Student :: Set(name, sex, age, num, school, major);
    Research_Direction = research_direction;
}
void Graduate :: Show()
{
    Student :: Show();
    cout << "研究方向:" << Research_Direction << endl;
}
