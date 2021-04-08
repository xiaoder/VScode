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
    cout << "请输入要判断的字符串:";
    cin >> str;
    int n = str.size();
    for (int i = 0; i < n/2; i++)
    {
        st.Push(str[i]);
    }
    char t;
    for (int i = (n+1)/2; i < n; i++)
    {
        t = st.Top();
        st.Pop();
        if(t != str[i])
        {
            cout << "不是中心对称字符串";
            return 0;
        }
    }
    cout << "是中心对称字符串";
    return 0;
}