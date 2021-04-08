#include <bits/stdc++.h>
#include <string>
using namespace std;

class Songer
{
    private:
    //string Name;
    char Name[20];
    int Fans_count;
    static int Count;
    public:
   // Songer(string name = "?",int fans_count = 0);
   Songer(char name[] = "?",int fans_count = 0);
    Songer(Songer & m);
    ~Songer();
    //void Set(string name,int x);
    void Set(char  name[],int x);
    Songer operator + (int x);
    bool operator > (Songer & t);
    friend bool operator == (Songer & p, Songer & q);
    Songer & operator ++();
    friend Songer & operator ++(Songer & t,int);
    friend ostream & operator << (ostream & p, Songer & q);
};
template <class T>
class Set;

template <class T>
ostream & operator << (ostream & os, Set<T> & t);

template <class T>
class Set
{
    private:
  //  string Set_Name;
    char Set_Name[20];
    T*  value;  //T����ָ�룬���ڴ�ż��ϵ�Ԫ�صĶ�̬���飬����Ϊlength
    int size;     //���ϴ�С��Ԫ�ظ�����
    int  length;  //��̬���鳤��
    public:
    Set(int len = 50);	//���캯��
    Set(Set<T>& A);	//�������캯�� ��ѡ����
    ~Set(  );  	//��������
    Set<T> & operator= (Set<T>& r);  //����"="ʹ���϶���������帳ֵ
    Set<T> &  operator+ (Set<T>& r);  //����"+"���������϶���Ĳ���
    void display( );  //�������������Ԫ��
    bool isExist(T v); //�жϼ������Ƿ����Ԫ��v
    void add(T v);   //�򼯺������һ��Ԫ��
    int getSize( )  ;	  // ���ؼ��ϵĴ�С
    int getLength( );  // ���ض�̬����value�Ĵ�С
    void Resize(int len);	// �޸Ķ�̬����value�Ĵ�С
    void Sort();
    friend ostream & operator << <T>(ostream & os, Set<T> & t);
   // void setname(string sn)
   void setname(char sn[])
    {
        strcpy(Set_Name,sn);
    }
   // string getsetname()
    char * getsetname()
    {
        return Set_Name;
    }
    T *getvalue()
    {
        return value;
    }
    T & operator [](int x)
    {
       // assert(x >= 0 && x < size);
        return value[x];
    }
};

template <class T>
void Set<T> :: Sort()
{
    int t;
    T temp;
    for (int i = 0; i < size; i++)
    {
        t = i;
        for (int j = i + 1; j < size; j++)
        {
            if(value[t] > value[j])
            {
                t = j;
            }
        }
        temp = value[t];
        value[t] = value[i];
        value[i] = temp;

    }
}

template <class T>
ostream & operator << (ostream & os, Set<T> & t)
{
    os << "��������" << t.Set_Name << endl;
    t.display();
    return os;
}
template <class T>
void Write_Set(Set<T> & t)
{
    //string filename, str;
    char filename[20],str[20];
    cout << "write " << t.getsetname() << " to:";
    cin >> filename;
    ofstream out(filename,ios::out);
   // str = t.getsetname();
   strcpy(str,t.getsetname());
    //out << str << endl;
    out.write(reinterpret_cast<char *>(&str),sizeof(str));
    t.setname(str);

    int ts = t.getSize();
    for(int i = 0; i < ts; i++)
    {
        out.write(reinterpret_cast<char *>(&(t[i])), sizeof(T));
    }
    out.close();
}
template <class T>
void Read_Set(Set<T> & t)
{
    //string filename, str;
    char filename[20],str[20];
    cout <<"read from:";
    cin >> filename;
    ifstream in(filename, ios::in);
   // getline(in, str);

   // t.setname(str);
    in.read(reinterpret_cast<char *>(&str),sizeof(str));
    t.setname(str);
    T temp;
    in.read(reinterpret_cast<char *>(&temp), sizeof(T));
    while(!in.eof())
    {
        t.add(temp);
        in.read(reinterpret_cast<char *>(&temp), sizeof(T));
    }
    in.close();
}

int main ()
{
   Set<int> a, c;
   a.setname("int:a");
   Set<Songer> b, d;
   b.setname("Songer:b");
   a.add(1);
   a.add(5);
   a.add(3);
   a.add(4);
   a.add(2);
   cout << a;
   a.Sort();
   cout << a;
    Songer t;
    t.Set("lisi", 4);
    b.add(t);
    t.Set("zhangsan", 3);
    b.add(t);
    t.Set("zhongxiaowu", 5);
    b.add(t);
    cout << b;
    b.Sort();
    cout << b;
    Write_Set(a);
    Read_Set(c);
    cout << c;
    Write_Set(b);
    cout<<sizeof(Songer)<<endl;
    Read_Set(d);
    cout << d;
}

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
//Songer :: Songer(string name, int fans_count)
Songer :: Songer(char  name[], int fans_count)
{
   // Name = name;
    strcpy(Name,name);
    Fans_count = fans_count;
    Count++;
}
Songer :: Songer(Songer & m)
{
    //Name = m.Name;
    strcpy(Name,m.Name);
    Fans_count = m.Fans_count;
    Count++;
}
Songer :: ~Songer ()
{
    Count--;
}
//void Songer :: Set(string name, int x)
void Songer :: Set(char name[], int x)
{
    //Name = name;
    strcpy(Name,name);
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
    p << "����:" << q.Name << endl << "��˿��:" << q.Fans_count << endl;
    return p;
}


template <class T>
Set<T> :: Set(int len)
{
    value = new T[len];
    length = len;
    size = 0;
    //Set_Name = "δ����";
    strcpy(Set_Name,"δ����");
}
template <class T>
Set<T> :: Set(Set<T>& A)
{
    //Set_Name = A.Set_Name;
    strcpy(Set_Name,A.Set_Name);
    length = A.length;
    size = A.size;
    value = new T[length];
    memcpy(value, A.value, length * sizeof(T));
}
template <class T>
Set<T> :: ~Set()
{
    size = 0;
    length = 0;
    delete [] value;
}
template <class T>
Set<T> & Set<T> :: operator= (Set<T>& r)
{
    if(&r != this)
    {
        if(length != r.length)
        {
            delete [] value;
            length = r.length;
            value = new T[length];
        }
        size = r.size;
        memcpy(value, r.value, length * sizeof(T));
    }
    return *this;
}
template <class T>
Set<T> & Set<T> :: operator + (Set<T>& r)
{
    static Set<T> temp;
    temp.Resize(0);
    for(int i = 0; i < size; i++)
    {
        temp.add(value[i]);
    }
    for(int i = 0; i < r.size; i++)
    {
        temp.add(r.value[i]);
    }
    return temp;
}
template <class T>
void Set<T> :: display()
{
    if(!size)
    {
        cout << "�ռ���";
    }
    for(int i = 0; i < size; i++)
    {
        cout << value[i];
    }
    cout << endl;
}
template <class T>
bool Set<T> :: isExist(T v)
{
    for(int i = 0; i < size; i++)
    {
        if(value[i] == v)
        {
            return true;
        }
    }
    return false;
}
template <class T>
void Set<T> :: add(T v)
{
    if(isExist(v))
    {
        cout << "��Ԫ���Ѿ�����" << endl;
        return;
    }
    if(size == length)
    {
        Resize(length + 10);
    }
    value[size] = v;
    size++;
}
template <class T>
int Set<T> :: getSize( )
{
    return size;
}
template <class T>
int Set<T> :: getLength( )
{
    return length;
}
template <class T>
void Set<T> :: Resize(int len)
{
  //  assert(len >= 0);
    if (len <= length)
    {
        size = len;
    }
    else
    {
        T * temp = new T[len];
        memcpy(temp, value, len * sizeof(T));
        size = length = len;
        delete [] value;
        value = temp;
    }
}
