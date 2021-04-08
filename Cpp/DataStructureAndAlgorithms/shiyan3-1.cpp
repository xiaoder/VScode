#include <iostream>
using namespace std;
typedef struct node
{
    int data;
    struct node *next;
} Node;
int main()
{
    Node *t, *s, *p, *q;
    s = new Node;
    s->data = 1;
    t = s;
    for(int i = 2; i <= 5; i++)
    {
        t->next = new Node;
        t = t->next;
        t->data = i;
    }
    t->next = s;
    t = s;
    do{
        cout << t->data << " ";
        t = t->next;
    }while(t != s);
    cout << endl;
    cout << "ÇëÊäÈës:";
    int x;
    cin >> x;
    p = s->next;
    q = s;
    while(p->next->data!=x)
    {
        q = p;
        p = p->next;
    }
    q->next = p->next;
    t = s;
    do{
        cout << t->data << " ";
        t = t->next;
    }while(t != s);
    cout << endl;
}