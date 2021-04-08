#include <iostream>
using namespace std;
typedef struct node
{
    int data;
    struct node *prior;
    struct node *next;
    int freq = 0;
} Node;
void lacate(Node *head, int x)
{
    Node *t = head->next, *p;
    do
    {
        if(x == t->data)
        {
            t->freq++;
            if(head->next == t)
            {
                return;
            }
            t->prior->next = t->next;
            t->next->prior = t->prior;
            p = t->prior;
            while(p != head ->next && p->freq < t->freq)
            {
                p = p->prior;
            }
            if(p == head->next && p ->freq <= t->freq)
            {
                t->next = head->next;
                t->prior = head->next->prior;
                t->prior->next = t;
                t->next->prior = t;
                head->next = t;
            }
            else
            {
                t->next = p->next;
                p->next = t;
                t->prior = p;
                t->next->prior = t;
            }
            
        }
        t = t->next;
    } while (t != head->next);
}
int main()
{
    Node *head, *tail, *t;
    t = tail = head = new Node;
    head->prior = nullptr;
    for (int i = 1; i <= 6; i++)
    {
        tail->next = new Node;
        tail = tail->next;
        tail->data = i;
        tail->prior = t;
        t = tail;
    }
    tail->next = head->next;
    head->next->prior = tail;
    t = head->next;
    do
    {
        cout << t->data << " ";
        t = t->next;
    } while (t != head->next);
    cout << endl;
    t = head->next;
    do
    {
        cout << t->freq << " ";
        t = t->next;
    } while (t != head->next);
    cout << endl;
    int flag = 1;
    while (flag)
    {
        int choose;
        cout << "1.查找\n2.输出\n3.退出\n";
        cout << "请选择:";
        cin >> choose;
        switch (choose)
        {
        case 1:
        {
            cout << "请输入要查找的数:";
            int x;
            cin >> x;
            lacate(head,x);
            break;
        }
        case 2:
        {
            t = head->next;
            do
            {
                cout << t->data << " ";
                t = t->next;
            } while (t != head->next);
            cout << endl;
            t = head->next;
            do
            {
                cout << t->freq << " ";
                t = t->next;
            } while (t != head->next);
            cout << endl;
            break;
        }
        case 3:
        {
            flag = 0;
            break;
        }

        }
    }
    cout << endl;
}