#include <iostream>
#include <string>
using namespace std;
typedef struct node
{
    char data;
    struct node *prior, *next;
} Node;
class Stack
{
    Node *head, *tail;
    public:
    Stack()
    {
        tail = head = new node;
        head->data = 0;
    }
    bool Empty()
    {
        if(!head->data)
        {
            return true;
        }
        return false;
    }
    void Push(char t)
    {
        head->data++;
        tail->next = new Node;
        tail->next->prior = tail;
        tail = tail->next;
        tail->data = t;
        tail->next = nullptr;
    }
    void Pop()
    {
        if(!Empty())
        {
            head->data--;
            tail = tail->prior;
            delete tail->next;
            tail->next = nullptr;
        }
    }
    int Size()
    {
        return head->data;
    }
    char Top()
    {
        return tail->data;
    }
    ~Stack()
    {
        Node *p = head;
        while(p)
        {
            Node *q = p;
            p = p->next;
            delete q;
        }
    }
};
int main()
{
    Stack st;
    string str;
    cout << "??????????????б└ик????:";
    cin >> str;
    int n = str.size();
    for (int i = 0; i < n; i++)
    {
        if(str[i] == '(')
        {
            st.Push('(');
        }
        else if (str[i] == ')')
        {
            if(st.Empty() && st.Top() != '(')
            {
                cout << "??????";
                return 0;
            }    
            st.Pop();
        }
    }
    if(st.Empty())
    {
        cout << "????";
    }
    else
    {
        cout << "??????";
    }
    return 0;
}