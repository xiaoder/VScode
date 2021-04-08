#include <iostream>
using namespace std;
class Node
{
    public:
    Node();
    Node(int x);
    void SetNext(Node *p);
    int GetDate();
    Node * GetNext();
    ~Node();
    private:
    int Date;
    Node * Next;
};

class Link
{
    private:
    Node * Head;
    int Num;
    public:
    Link(int n = 0);
    Link(Link & p);
    ~Link();
    void LinkPrint();
    Node * GetHead();
    void Insert(int x);
    void Delete(int x);
    void Connect(Link & p);
};
int main()
{
    Link a, b(3), c(b);
    a.LinkPrint();
    b.LinkPrint();
    c.LinkPrint();
    cout << a.GetHead() << endl;
    cout << b.GetHead() << endl;
    cout << c.GetHead() << endl;
    a.Insert(1);
    a.Insert(5);
    a.Insert(4);
    a.Insert(2);
    a.Insert(3);
    a.LinkPrint();
    a.Delete(3);
    a.LinkPrint();
    a.Connect(b);
    a.LinkPrint();
    return 0;
}

Node :: Node()
{
    cin >> Date;
    Next = NULL;
}
Node :: Node (int x)
{
    Date = x;
    Next = NULL;
}
void Node :: SetNext(Node *p)
{
    Next = p;
}
int Node :: GetDate()
{
    return Date;
}
Node * Node :: GetNext()
{
    return Next;
}
Node :: ~Node()
{
    cout << Date << "被析构!" << endl;
}
Link :: Link(int n)
{
    Head = NULL;
    Num = 0;
    for (int i = 0, x = 8; i < n; i++, x++)
    {
        Insert(x);
    }
}
Link :: Link(Link &m)
{
    Num = m.Num;
    if(Num == 0)
    {
        Head = NULL;
    }
    else
    {
        Node * p, *q;
        q = m.Head;
        p = Head = new Node(q->GetDate());
        for (int i = 0; i < Num-1; i++)
        {
            q = q->GetNext();
            p->SetNext(new Node(q->GetDate()));
            p = p->GetNext();
        }
    }
}
Link :: ~Link()
{
    Node *p,*q;
    p = Head;
    while(p)
    {
        q = p;
        p = p->GetNext();
        delete q;
    }
}
void Link :: LinkPrint()
{
    Node *p;
    p = Head;
    while(p)
    {
        cout << p->GetDate() << " ";
        p = p->GetNext();
    }
    cout << endl;
}
Node *Link :: GetHead()
{
    return Head;
}
void Link :: Insert(int x)
{
    Num++;
    if(!Head)
    {
        Head = new Node(x);
        return;
    }
    Node *p, *q, *t = new Node(x);
    if(x <= Head->GetDate())
    {
        t->SetNext(Head);
        Head = t;
    }
    else
    {
        p = Head;
        while(p && p->GetDate() < x)
        {
            q = p;
            p = p->GetNext();
        }
        t->SetNext(p);
        q->SetNext(t);
    }
}
void Link :: Delete(int x)
{
    Node *p, *q = Head;
    if(x == Head->GetDate())
    {
        Head = Head->GetNext();
        delete q;
        Num--;
    }
    while(q && q->GetDate() != x)
    {
        p = q;
        q = q->GetNext();
    }
    if(q)
    {
        p->SetNext(q->GetNext());
        delete q;
        Num--;
    }
    else
    {
        cout << "没有该元素!" << endl;
    }

}
void Link :: Connect(Link &m)
{
    Node *p = Head, *q = m.Head;
    while(p->GetNext())
    {
        p = p->GetNext();
    }
    for(int i = 0; i < m.Num; i++)
    {
        p->SetNext(new Node(q->GetDate()));
        p = p->GetNext();
        q = q->GetNext();
    }
}
