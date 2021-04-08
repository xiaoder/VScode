#include <iostream>
using namespace std;
typedef struct node
{
    int data;
    struct node *next;
} Node;
int main()
{
    Node *head;
    head = new Node;
    head->next = nullptr;
    Node *p, *q, *t;
    p = head;
    for (int i = 1; i < 10; i += 2)
    {
        t = new Node;
        t->next = NULL;
        t->data = i;
        p->next = t;
        p = p->next;
    }
    head->data = 5;
    p = head;
    while (p)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
    int x;
    cout << "请输入要插入的整数:";
    cin >> x;
    q = head;
    p = head->next;
    while (p)
    {
        if (x < p->data)
        {
            t = new Node;
            t->next = p;
            t->data = x;
            q->next = t;
            break;
        }
        q = p;
        p = p->next;
    }
    if (!p)
    {
        t = new Node;
        t->next = NULL;
        t->data = x;
        q->next = t;
    }
    head->data++;
    p = head;
    while (p)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
    p = head;
    while (p)
    {   q = p;
        p = p->next;
        delete q;
    }
    return 0;
}