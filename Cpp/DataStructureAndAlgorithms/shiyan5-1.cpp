#include <iostream>
#include <queue>
using namespace std;
typedef struct node
{
    int data;
    struct node *leftChild = nullptr;
    struct node *rightChild = nullptr;
} Node;
int d = 0;
void deep(Node *t, int x)
{
    if(x > d)
    {
        d = x;
    }
    cout << t->data << " ";
    if(t->leftChild)
    {
        deep(t->leftChild, x + 1);
    }
    if(t->rightChild)
    {
        deep(t->rightChild, x + 1);
    }
}
int main()
{
    queue<Node *> que;
    Node *t1, *t2, *t3, *head;
    head = new Node;
    head->data = 1;
    que.push(head);
    cout << "请输入一个大于1的整数:";
    int x;
    cin >> x;
    for (int i = 2; i <= x; i += 2)
    {
        t1 = que.front();
        t2 = new Node;
        t2->data = i;
        t3 = new Node;
        t3->data = i + 1;
        t1->leftChild = t2;
        t1->rightChild = t3;
        que.pop();
        que.push(t2);
        que.push(t3);
    }
    if(x % 2 == 0)
    {
        t1->rightChild = nullptr;
    }
    deep(head, 1);
    cout << endl << d << endl;
    return 0;
}