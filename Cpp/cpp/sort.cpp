#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
typedef struct Student 
{
    char name[10];
    long long id;
} Student;
struct Rule1
{
    bool operator()(const int & a1, const int & a2) const
    {
        return a1 > a2;
    }
};
struct Rule2
{
    bool operator () (const int & a1, const int & a2) const 
    {
        return a1 % 10 < a2 % 10;
    }
};
struct StudentRule1
{
    bool operator () (const Student & s1, const Student & s2) const
    {
        if(strcmp(s1.name,s2.name)<0)
            return true;
        return false;
    }
};
struct StudentRule2
{
    bool operator ()(const Student & s1,const Student & s2) const
    {
        return s1.id < s2.id;
    }
};
int main()
{
    int aa[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    sort(aa, aa + 10, Rule1());
    for (int i = 0; i < 10; i++)
    {
        cout << aa[i] <<" ";
    }
    cout << endl;
    sort(aa, aa + 10, Rule2());
    for (int i = 0; i < 10; i++)
    {
        cout << aa[i] <<" ";
    }
}