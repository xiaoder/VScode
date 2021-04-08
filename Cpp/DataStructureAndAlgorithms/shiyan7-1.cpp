#include <iostream>
#include <vector>
using namespace std;
typedef struct
{
    int n;
    int e;
    vector<vector<int>> edge;
    vector<char> node;
} Graph;
Graph creatGraph()
{
    Graph t;
    cout << "请输入点数和边数:";
    cin >> t.n >> t.e;
    t.node.resize(t.n);
    cout << "请输入顶点:";
    for (int i = 0; i < t.n; i++)
    {
        cin >> t.node[i];
    }
    for (int i = 0; i < t.n; i++)
    {
        t.edge.push_back(vector<int>(t.n, 2147483647));
    }
    cout << "请输入边:" << endl;
    for (int i = 0; i < t.e; i++)
    {
        int x, y;
        cin >> x >> y;
        t.edge[x][y] = 1;
        t.edge[y][x] = 1;
    }
    return t;
}

vector<int> book;
vector<int> path;

void dfs(Graph t, int x, int y)
{
    if (x == y)
    {
        for (int i = 0; i < path.size(); i++)
        {
            cout << t.node[path[i]] << "->";
        }
        cout << t.node[y];
        cout << endl;
        return;
    }
    for (int i = 0; i < t.n; i++)
    {
        if (!book[i] && t.edge[x][i] < 2147483647)
        {
            book[x] = 1;
            path.push_back(x);
            dfs(t, i, y);
            path.pop_back();
            book[i] = 0;
        }
    }
}

int main()
{
    Graph t = creatGraph();
    for (int i = 0; i < t.n; i++)
    {
        book.push_back(0);
    }
    char ch1, ch2;
    cout << "请输入起点和终点:";
    cin >> ch1 >> ch2;
    int x, y;
    for (int i = 0; i < t.n; i++)
    {
        if (t.node[i] == ch1)
        {
            x = i;
        }
        else if (t.node[i] == ch2)
        {
            y = i;
        }
    }
    dfs(t, x, y);
    return 0;
}