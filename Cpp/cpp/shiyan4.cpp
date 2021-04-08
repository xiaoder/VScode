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
    Graduate a, b("����", 1, 20, "20191234", "��������ѧ", "�����", "�˹�����"), c(b);
    a.Show();
    b.Show();
    c.Show();
    c.Set("����", 0, 21, "20194321", "��������ѧ", "�������", "������");
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
    cout << "����:" << Name << endl;
    if(Sex)
    {
        cout << "�Ա�:" << "��" << endl;
    }
    else
    {
        cout << "�Ա�:" << "Ů" << endl;
    }
    
    cout << "����:" << Age << endl;
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
    cout << "ѧ��:" << Num << endl;
    cout << "ѧУ:" << School << endl;
    cout << "רҵ:" << Major << endl;
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
    cout << "�о�����:" << Research_Direction << endl;
}
