#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int random(int m, int n)
{
    return rand() % n + m;
}

int compareCount, swapCount;

typedef struct BSTNode
{
    int data;
    struct BSTNode *leftChild;
    struct BSTNode *rightChild;

} BSTNode;

bool insertBST(BSTNode *&t, int x)
{
    BSTNode *s;
    if (!t)
    {
        s = new BSTNode;
        s->data = x;
        s->leftChild = nullptr;
        s->rightChild = nullptr;
        t = s;
        return true;
    }
    else if (x == t->data)
    {
        return false;
    }
    else if (x < t->data)
    {
        return insertBST(t->leftChild, x);
    }
    else
    {
        return insertBST(t->rightChild, x);
    }
}

BSTNode *creatBST()
{
    BSTNode *t = nullptr;
    srand(int(time(0)));
    cout << "���������ݸ���:";
    int n;
    cin >> n;
    int *arr = new int[n];
    cout << "���������ݷ�Χ:";
    int start, end;
    cin >> start >> end;
    cout << "������ɵ�����:";
    for (int i = 0; i < n; i++)
    {
        do
        {
            arr[i] = random(start, end);
        } while (!insertBST(t, arr[i]));
        cout << arr[i] << " ";
    }
    cout << endl;
    return t;
}

void midOrderTraverse(BSTNode *t)
{
    if (t)
    {
        if (t->leftChild)
        {
            midOrderTraverse(t->leftChild);
        }
        cout << t->data << " ";
        if (t->rightChild)
        {
            midOrderTraverse(t->rightChild);
        }
    }
};

BSTNode *searchBST(BSTNode *t, int x)
{
    if (!t)
    {
        return t;
    }
    else if (x == t->data)
    {
        compareCount++;
        return t;
    }
    else if (x < t->data)
    {
        compareCount++;
        return searchBST(t->leftChild, x);
    }
    else
    {
        compareCount++;
        return searchBST(t->rightChild, x);
    }
}

bool deleteBST(BSTNode *&t, int x, BSTNode *parent = nullptr)
{
    if (!t)
    {
        return false;
    }
    else if (x == t->data)
    {
        if (!t->leftChild && !t->rightChild)
        {
            if (!parent)
            {
                t = nullptr;
            }
            else if (parent->leftChild == t)
            {
                parent->leftChild = nullptr;
            }
            else
            {
                parent->rightChild = nullptr;
            }
        }
        else if (t->leftChild && t->rightChild)
        {
            BSTNode *p = t->rightChild;
            while (p->leftChild)
            {
                p = p->leftChild;
            }
            t->data = p->data;
            deleteBST(t->rightChild, p->data);
        }
        else
        {
            if (!parent)
            {
                if (t->leftChild)
                {
                    t = t->leftChild;
                }
                else
                {
                    t = t->rightChild;
                }
            }
            else if (parent->leftChild == t)
            {
                if (t->leftChild)
                {
                    parent->leftChild = t->leftChild;
                }
                else
                {
                    parent->leftChild = t->rightChild;
                }
            }
            else
            {
                if (t->leftChild)
                {
                    parent->rightChild = t->leftChild;
                }
                else
                {
                    parent->rightChild = t->rightChild;
                }
            }
        }
        return true;
    }
    else if (x < t->data)
    {
        return deleteBST(t->leftChild, x, t);
    }
    else
    {
        return deleteBST(t->rightChild, x, t);
    }
    return false;
}

void menu()
{
    cout << "1������ \n2����� \n3������ \n4������ \n5��ɾ�� \n0���˳�" << endl;
    cout << "��ѡ��:";
}

int main()
{
    BSTNode *t;
    int choose;
    int flag = 1;
    while (flag)
    {
        menu();
        cin >> choose;
        switch (choose)
        {
        case 1: //��������������
        {
            t = creatBST();
            break;
        }
        case 2: // ����������
        {
            midOrderTraverse(t);
            cout << endl;
            break;
        }
        case 3: //����
        {
            cout << "������Ҫ���������:";
            int x;
            cin >> x;
            if (insertBST(t, x))
            {
                cout << "����ɹ�" << endl;
            }
            else
            {
                cout << "����ʧ��" << endl;
            }

            break;
        }
        case 4: // ����
        {
            compareCount = 0;
            cout << "������Ҫ���ҵ�����:";
            int x;
            cin >> x;
            if (searchBST(t, x))
            {
                cout << "���ҳɹ�" << endl;
                cout << "�Ƚϴ���Ϊ:" << compareCount << endl;
            }
            else
            {
                cout << "�����ʧ��" << endl;
                cout << "�Ƚϴ���Ϊ:" << compareCount << endl;
            }
            break;
        }
        case 5: //ɾ��
        {
            cout << "������Ҫɾ��������:";
            int x;
            cin >> x;
            if (deleteBST(t, x))
            {
                cout << "ɾ���ɹ�" << endl;
            }
            else
            {
                cout << "ɾ��ʧ��" << endl;
            }
            break;
        }
        default:
        {
            flag = 0;
        }
        }
    }
    return 0;
}