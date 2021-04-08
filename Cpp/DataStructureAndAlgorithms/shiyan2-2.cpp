#include <iostream>
using namespace std;
typedef struct node
{
    int data;
    struct node * next;
}Node;
int main()
{
    Node *head;
    head = new Node;
    head-> next = NULL; 
    Node *p, *q, *t;
    p = head;
    for (int i = 1; i < 10; i += 2)
    {
        t = new Node;
        t-> next = NULL;
        t->data = i;
        p->next = t;
        p = p->next;
    }
    head->data = 5;
    p = head;
    while(p)
    {
        cout << p->data << " ";
        p = p-> next;
    }
    cout << endl;
    p = head->next;
    head->next = NULL;
    while(p)
    {
        q = p;
        p = p->next;
        q->next = head->next;
        head->next = q;
    }
    p = head;
    while(p)
    {
        cout << p->data << " ";
        p = p-> next;
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