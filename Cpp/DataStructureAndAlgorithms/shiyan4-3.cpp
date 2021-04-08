#include <iostream>
using namespace std;
typedef struct node
{
    int data;
    struct node *next;
} Node;
class Queue
{
    Node *head, *tail;
    public:
    Queue()
    {
        head = tail = new Node;
        tail->next = head;
    }
    void Empty()
    {
        Node *p = tail->next->next;
        tail  = head;
        tail->next = head;
        while(p != tail->next)
        {
            Node *q = p;
            p = p->next;
            delete q;
        }
    }
    void Push(int x)
    {
        tail->next = new Node;
        tail = tail->next;
        tail->data = x;
        tail->next = head;
    }
    void Pop()
    {
        if(tail->next == tail)
        {
            cout << "空队列无法出队\n";
        }
        else
        {
            Node *t = tail->next->next;
            tail->next->next = t->next;
            if(tail == t)
            {
                tail = head;
            }
            delete t;
        }
    }
    void Print()
    {
        Node *p = tail->next->next;
        while(p != tail->next)
        {
            cout << p->data << " ";
            p = p->next;
        }
        if(head == tail)
        {
            cout << "空队列";
        }
        cout << endl;
    }
};
int main()
{
    Queue a;
    int flag = 1;
    while(flag)
    {
        int choose;
        cout << "1.入队\n2.出队\n3.队置空\n4.输出\n5.退出\n";
        cin >> choose;
        switch (choose)
        {
            case 1:
            {
                cout << "请输入一个整数:";
                int x;
                cin >> x;
                a.Push(x);
                break;
            }
            case 2:
            {
                a.Pop();
                break;
            }
            case 3:
            {
                a.Empty();
                break;
            }
            case 4:
            {
                a.Print();
                break;
            }
            case 5:
            {
                flag = 0;
                break;
            }
    
        }
    }
}