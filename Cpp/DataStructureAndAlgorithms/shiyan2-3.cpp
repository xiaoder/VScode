#include <iostream>
using namespace std;
typedef struct node
{
    int data;
    struct node *next;
} Node;
int main()
{
    Node *head1, *head2;
    head1 = new Node;
    head1->next = NULL;
    head2 = new Node;
    head2->next = NULL;
    Node *p, *q, *t;
    Node *m, *n, *o;
    p = head1;
    for (int i = 1; i < 10; i += 2)
    {
        t = new Node;
        t->next = NULL;
        t->data = i;
        p->next = t;
        p = p->next;
    }
    head1->data = 5;
    p = head2;
    for (int i = 3; i <= 7; i++)
    {
        t = new Node;
        t->next = NULL;
        t->data = i;
        p->next = t;
        p = p->next;
    }
    head2->data = 5;
    p = head1;
    while (p)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
    p = head2;
    while (p)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;

    p = head1->next;
    head1->next = NULL;
    m = head2->next;
    while (p && m)
    {
        q = p;
        p = p->next;
        n = m;
        m = m->next;
        if (n->data > q->data)
        {
            q->next = head1->next;
            head1->next = q;
            n->next = head1->next;
            head1->next = n;
        }
        else
        {
            n->next = head1->next;
            head1->next = n;
            q->next = head1->next;
            head1->next = q;
        }
    }
    while (p)
    {
        q = p;
        p = p->next;
        q->next = head1->next;
        head1->next = q;
    }
    while (m)
    {
        n = m;
        m = m->next;
        n->next = head1->next;
        head1->next = n;
    }
    head1->data = 10;
    p = head1;
    while (p)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
    p = head1;
    while (p)
    {   q = p;
        p = p->next;
        delete q;
    }
    return 0;
}