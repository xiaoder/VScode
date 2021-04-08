#include <iostream>
#include <queue>
#include <vector>
#include <stack>
using namespace std;
typedef struct EdgeNode
{
    int adjvex;
    struct EdgeNode *next;
} EdgeNode;
typedef struct VertexNode
{
    char data;
    struct EdgeNode *firstedge;
} VertexNode;
typedef struct Graph
{
    int n;
    int e;
    struct VertexNode *adjlist;
} Graph;
typedef struct PathNode
{
    int data;
    struct PathNode *front;
} PathNode;

vector<int> book;

Graph creatGraph()
{
    Graph t;
    cout << "请输入顶点数和边数:";
    cin >> t.n >> t.e;
    t.adjlist = new VertexNode[t.n];
    cout << "请输入顶点:";
    for (int i = 0; i < t.n; i++)
    {
        cin >> t.adjlist[i].data;
        t.adjlist[i].firstedge = nullptr;
    }
    for (int i = 0; i < t.e; i++)
    {
        int x, y;
        cout << "请输入第" << i + 1 << "条边的两个顶点";
        cin >> x >> y;
        EdgeNode *p;
        p = new EdgeNode;
        p->adjvex = y;
        p->next = t.adjlist[x].firstedge;
        t.adjlist[x].firstedge = p;
        p = new EdgeNode;
        p->adjvex = x;
        p->next = t.adjlist[y].firstedge;
        t.adjlist[y].firstedge = p;
    }
    return t;
}

vector<int> bfs(Graph t, int x, int y)
{
    queue<PathNode *> que;
    vector<int> path;
    stack<int> st;
    PathNode *pn = new PathNode;
    pn->data = x;
    pn->front = nullptr;
    book[x] = 1;
    que.push(pn);
    while (!que.empty())
    {
        EdgeNode *p = t.adjlist[que.front()->data].firstedge;
        while (p)
        {
            if (!book[p->adjvex])
            {
                pn = new PathNode;
                pn->data = p->adjvex;
                pn->front = que.front();
                if (p->adjvex == y)
                {
                    while (pn)
                    {
                        st.push(pn->data);
                        pn = pn->front;
                    }
                    while (!st.empty())
                    {
                        path.push_back(st.top());
                        st.pop();
                    }
                    return path;
                }
                else
                {
                    que.push(pn);
                    book[pn->data] = 1;
                }
            }
            p = p->next;
        }
        que.pop();
    }
    return {};
}

int main()
{
    Graph t = creatGraph();
    book.resize(t.n, 0);
    cout << "请输入起点和终点:";
    int x, y;
    cin >> x >> y;
    vector<int> path = bfs(t, x, y);
    for (int i = 0; i < path.size() - 1; i++)
    {
        cout << t.adjlist[path[i]].data << "->";
    }
    if (!path.empty())
        cout << t.adjlist[path.back()].data << endl;
    else
        cout << "没路径";
    return 0;
}