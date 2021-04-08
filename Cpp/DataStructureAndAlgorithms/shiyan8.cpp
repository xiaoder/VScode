#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef struct Graph
{
    int n;                    //ͼ�Ķ�����
    int e;                    //ͼ�ı���
    vector<vector<int>> edge; //vector��ά���飬���ڴ����ٽ־���
    vector<char> node;        //vectorһά���飬���ڴ洢�ڵ���Ϣ
} Graph;

typedef struct Edge
{
    int start;
    int end;
    int weight;
} Edge;

typedef struct X //��������
{
    int fromvex; //U���ж������
    int endvex;  //V-U���ж������
    int length;  //�ߵ�Ȩֵ
} closedge;

bool cmp_edge_weight(Edge &a, Edge &b)
{
    return a.weight < b.weight;
}

Graph creatGraph() //����ͼ
{
    Graph t;
    t.n = 9;
    t.e = 11;
    t.node.resize(t.n);
    for (int i = 0, ch = 'A'; i < t.n; i++, ch++)
        t.node[i] = ch;

    for (int i = 0; i < t.n; i++)
        t.edge.push_back(vector<int>(t.n, 2147483647));

    t.edge[0][1] = 6; //AB
    t.edge[1][0] = 6;

    t.edge[0][2] = 4; //AC
    t.edge[2][0] = 4;

    t.edge[0][3] = 5; //AD
    t.edge[3][0] = 5;

    t.edge[1][4] = 1; //BE
    t.edge[4][1] = 1;

    t.edge[2][4] = 1; //CE
    t.edge[4][2] = 1;

    t.edge[3][5] = 2; //DF
    t.edge[5][3] = 2;

    t.edge[4][6] = 9; //EG
    t.edge[6][4] = 9;

    t.edge[4][7] = 7; //EH
    t.edge[7][4] = 7;

    t.edge[5][7] = 4; //FH
    t.edge[7][5] = 4;

    t.edge[6][8] = 2; //GI
    t.edge[8][6] = 2;

    t.edge[7][8] = 4; //HI
    t.edge[8][7] = 4;

    return t;
}
int getIndex(Graph t, char ch) //��ȡ�ַ����±꣬��ͼ�д��ڸýڵ㣬�򷵻��±꣬�����ڷ���-1
{
    for (int i = 0; i < t.n; i++)
    {
        if (ch == t.node[i])
        {
            return i;
        }
    }
    return -1;
}

vector<int> book;

int findRoot(int x)
{
    while (book[x] != x)
    {
        x = book[x];
    }
    return x;
}

vector<Edge> kruskal(Graph t)
{
    vector<Edge> all_edge, result;
    for (int i = 0; i < t.edge.size(); i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (t.edge[i][j] < 2147483647)
            {
                Edge temp;
                temp.start = i;
                temp.end = j;
                temp.weight = t.edge[i][j];
                all_edge.push_back(temp);
            }
        }
    }
    sort(all_edge.begin(), all_edge.end(), cmp_edge_weight);
    book.clear();
    for (int i = 0; i < all_edge.size(); i++)
    {
        book.push_back(i);
    }

    for (int i = 0; i < all_edge.size(); i++)
    {
        if (findRoot(all_edge[i].start) != findRoot(all_edge[i].end))
        {
            book[findRoot(all_edge[i].end)] = all_edge[i].start;
            result.push_back(all_edge[i]);
        }
    }

    return result;
}
void PRIM(Graph G, closedge T[]) //Prim�㷨
{
    int Min = 0, Max = 2147483647;
    int j, k, m, v, d;
    closedge e;
    for (j = 1; j < G.n; j++) //���������ʼ��
    {
        T[j - 1].fromvex = 1;
        T[j - 1].endvex = j + 1;
        T[j - 1].length = G.edge[0][j];
    }
    for (k = 0; k < G.n - 1; k++) //ѡȡ�������⼯����̱�
    {
        Min = Max;
        for (j = k; j < G.n - 1; j++)
            if (T[j].length < Min)
            {
                Min = T[j].length;
                m = j;
            }
        e = T[m];
        T[m] = T[k];
        T[k] = e;
        v = T[k].endvex;
        for (j = k + 1; j < G.n - 1; j++)
        {
            d = G.edge[v - 1][T[j].endvex - 1];
            if (d < T[j].length)
            {
                T[j].length = d;
                T[j].fromvex = v;
            }
        }
    }
}
void menu()
{
    cout << "**********************************************************************" << endl
         << "*                                  G-----2-----I                     *" << endl
         << "*                                  |           |                     *" << endl
         << "*                                  |           |                     *" << endl
         << "*                                  9           4                     *" << endl
         << "*                                  |           |                     *" << endl
         << "*                                  |           |                     *" << endl
         << "*                      B-----1-----E-----7-----H                     *" << endl
         << "*                      |           |           |                     *" << endl
         << "*                      |           |           |                     *" << endl
         << "*                      6           1           |                     *" << endl
         << "*                      |           |           |                     *" << endl
         << "*                      |           |           |                     *" << endl
         << "*                      A-----4-----C           4                     *" << endl
         << "*                      |                       |                     *" << endl
         << "*                      |                       |                     *" << endl
         << "*                      5                       |                     *" << endl
         << "*                      |                       |                     *" << endl
         << "*                      |                       |                     *" << endl
         << "*                      D-----------2-----------F                     *" << endl
         << "*                  1.����ķ(Prim)�㷨������С������                  *" << endl
         << "*                  2.��³˹����(Kruscal)�㷨������С������           *" << endl
         << "*                                                                    *" << endl
         << "**********************************************************************" << endl
         << "������ѡ��:";
}
int main()
{
    int choose = 1;
    Graph t = creatGraph(); //ͼ�ĳ�ʼ��
    while (choose != 0)
    {
        system("cls");
        menu();          //���ͼ�μ��˵�
        cin >> choose;   //����ѡ��
        if (choose == 1) //����ķ�㷨
        {
            closedge T[8];
            PRIM(t, T);
            for (int i = 0; i < t.n - 1; i++)
                cout << t.node[T[i].fromvex - 1] << " "
                     << t.node[T[i].endvex - 1] << " "
                     << T[i].length << endl;
        }
        else //��³˹�����㷨
        {
            vector<Edge> result = kruskal(t);
            for (int i = 0; i < result.size(); i++)
            {
                cout << t.node[result[i].start] << " " << t.node[result[i].end] << " " << result[i].weight << endl;
            }
        }
        system("pause");
    }
    return 0;
}
