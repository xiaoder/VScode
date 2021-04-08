#include <iostream>
#include <stack>
#include <vector>
struct node
{
    int data, num;
};
using namespace std;
int main ()
{
    vector<struct node> binaryTree;
    cout << "请输入一个大于1的整数:";
    int n;
    cin >> n;
    struct node t;
    t.data = n;
    t.num = 0;
    binaryTree.push_back(t);
    for (int i = 1; i <= n; i++)
    {
        t.data = i;
        t.num = i;
        binaryTree.push_back(t);
    }
    stack<struct node> st;
    int p = 1;
    while(p <= n || !st.empty())
    {
        if(p <= n)
        {
            cout << binaryTree[p].data << " ";
            st.push(binaryTree[p]);
            p *= 2;
        }
        else
        {
            p = st.top().num;
            st.pop();
            p = p * 2 + 1;
        }
    }
    cout << endl;
    return 0;
}