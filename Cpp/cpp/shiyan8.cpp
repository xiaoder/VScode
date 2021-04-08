#include <bits/stdc++.h>
#include <string>
using namespace std;
class Student
{
    private:
    string Num;
    string Name;
    string Sex;
    int Score;
    public:
    Student(string num  = "?", string name = "?", string sex = "?", int score = 0)
    {
        Num = num;
        Name = name;
        Sex = sex;
        Score = score;
    }
    Student(const Student & t)
    {
        Num = t.Num;
        Name = t.Name;
        Sex = t.Sex;
        Score = t.Score;
    }
    void Set(string num, string name, string sex, int score)
    {
        Num = num;
        Name = name;
        Sex = sex;
        Score = score;
    }
    void Show()
    {
        cout << "学号:" << Num << endl;
        cout << "姓名:" << Name << endl;
        cout << "性别:" << Sex << endl;
        cout << "得分:" << Score << endl;
    }
    bool operator < (Student & t)
    {
        if (Score < t.Score)
        return true;
        return false;
    }
    bool operator > (Student & t)
    {
        if (Score > t.Score)
        return true;
        return false;
    }
    bool operator == (Student & t)
    {
        if (Score == t.Score)
        return true;
        return false;
    }
};
class StudentControl
{
    vector<Student> listStu;
    int Num;
    public:
    StudentControl(int n = 0)
    {
        Num = n;
        for(int i = 0; i < n; i++)
        {
            input();
        }
    }
    ~StudentControl()
    {

    }
    void loadFromFile(string filename)
    {
        ifstream in(filename,ios::in);
        Student temp;
        in.read(reinterpret_cast<char *>(&temp), sizeof(Student));
        while(!in.eof())
        {
            listStu.push_back(temp);
            in.read(reinterpret_cast<char *>(&temp), sizeof(Student));
            Num++;
        }
        in.close();
    }
    void writeToFile(string filename)
    {
        ofstream out(filename, ios::out);
        Student temp;
        for (vector<Student> :: iterator i = listStu.begin(); i != listStu.end(); i++)
        {
            temp = *i;
            out.write(reinterpret_cast<char *>(&temp), sizeof(Student));
        }
    }
    void input()
    {
        string name, num, sex;
        int score;
        cin >> num >> name >> sex >> score;
        Student temp;
        temp.Set(num, name, sex, score);
        listStu.push_back(temp);
        Num++;
    }
    void Sort()
    {
        sort(listStu.begin(),listStu.end());
    }
    void dispaly()
    {
        for (vector<Student> :: iterator i = listStu.begin(); i != listStu.end(); i++)
        {
            i->Show();
        }
    }
};
int main ()
{
    StudentControl a, b;
    a.input();
    a.input();
    a.input();
    a.dispaly();
    cout << endl;
    a.Sort();
    a.dispaly();
    cout << endl;
    a.writeToFile("1.txt");
    b.loadFromFile("1.txt");
    b.dispaly();
    cout << endl;
    return 0;
}
