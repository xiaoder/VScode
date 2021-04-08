#include <iostream>
#include <queue>
#include <stack>
using namespace std;
typedef struct node
{
    int data;
    struct node *leftChild = nullptr;
    struct node *rightChild = nullptr;
    int flag = 1;
} Node;
void creat(Node* &t)
{
    int x;
    cin >> x;
    if(x)
    {
        t = new Node;
        t->data = x;
        creat(t->leftChild);
        creat(t->rightChild);
    }
    else
    {
        t = nullptr;
    }
    
}
int main()
{
    Node *t1, *t2, *t3, *head, *p;
    creat(head);
    stack<Node*> st;
    cout << "Ç°Ðò:";
    p = head;
    while(p || !st.empty())
    {
        if(p)
        {
            cout << p->data << " ";
            st.push(p);
            p = p->leftChild;
        }
        else
        {
            p = st.top();
            st.pop();
            p = p->rightChild;
        }
    }
    cout << endl;
    cout << "ÖÐÐò:";
    p = head;
    while(p || !st.empty())
    {
        if(p)
        {
            st.push(p);
            p = p->leftChild;
        }
        else
        {
            p = st.top();
            cout << p->data << " ";
            st.pop();
            p = p->rightChild;
        }
    }
    cout << endl;
    cout << "ºóÐò:";
    p = head;
    while(1)
    {
        if(p)
        {
            st.push(p);
            p = p->leftChild;
        }
        else
        {
            p = st.top();
            st.pop();
            while(1)
            {
                if(p->flag)
                {
                    p->flag--;
                    st.push(p);
                    p = p->rightChild;
                    break;
                }
                else
                {
                    cout << p->data << " ";
                    if(st.empty())
                    {
                        exit(0);
                    }
                    p = st.top();
                    st.pop();
                }
                
            }
        }
    }
    return 0;
}