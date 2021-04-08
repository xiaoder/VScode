#include <iostream>
using namespace std;
typedef struct node
{
    char data;
    struct node *next = nullptr;
} Node;
int main()
{
    Node *head, *tail, *p, *q;
    head = tail = new Node;
    tail->data = 0;
    tail->next = new Node;
    tail = tail->next;
    tail->data = '1';
    tail->next = new Node;
    tail = tail->next;
    tail->data = 'c';
    tail->next = new Node;
    tail = tail->next;
    tail->data = '!';
    tail->next = new Node;
    tail = tail->next;
    tail->data = 'h';
    tail->next = new Node;
    tail = tail->next;
    tail->data = '$';
    tail->next = new Node;
    tail = tail->next;
    tail->data = '2';
    tail->next = new Node;
    tail = tail->next;
    tail->data = '3';
    tail->next = new Node;
    tail = tail->next;
    tail->data = 'i';
    tail->next = new Node;
    tail = tail->next;
    tail->data = 'n';
    tail->next = new Node;
    tail = tail->next;
    tail->data = '#';
    tail->next = new Node;
    tail = tail->next;
    tail->data = 'a';
    p = head->next;
    while (p)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
    Node *head1, *head2, *head3, *tail1, *tail2, *tail3;
    head1 = tail1 = new Node;
    head1->data = 0;
    head2 = tail2 = new Node;
    head2->data = 0;
    head3 = tail3 = new Node;
    head3->data = 0;
    p = head->next;
    while (p)
    {
        q = p;
        p = p->next;
        if (isdigit(q->data))
        {
            tail1->next = q;
            tail1 = q;
        }
        else if (isalpha(q->data))
        {
            tail2->next = q;
            tail2 = q;
        }
        else
        {
            tail3->next = q;
            tail3 = q;
        }
    }
    tail1->next = head1->next;
    tail2->next = head2->next;
    tail3->next = head3->next;
    p = head1->next;
    do
    {
        cout << p->data << " ";
        p = p->next;
    } while (p != head1->next);
    cout << endl;
    p = head2->next;
    do
    {
        cout << p->data << " ";
        p = p->next;
    } while (p != head2->next);
    cout << endl;
    p = head3->next;
    do
    {
        cout << p->data << " ";
        p = p->next;
    } while (p != head3->next);
    cout << endl;
    return 0;
}