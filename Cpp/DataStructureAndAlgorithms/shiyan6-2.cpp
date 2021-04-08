#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
typedef struct letterFrequency
{
    char letter;
    int frequency;
} letterFrequent;
typedef struct huffmanTreeNode
{
    char letter;
    int frequency;
    int leftchild;
    int rightchild;
    int parent;
} huffmanTreeNode;
typedef struct letterCode
{
    char letter;
    string code;
} letterCode;
bool cmp(letterFrequency t1, letterFrequency t2)
{
    return t2.frequency < t1.frequency;
}
string chooseFile()
{
    string fileName = "D:\\Desktop\\a.txt";
    // cout << "请输入文件名:";
    // cin >> fileName;
    ifstream in;
    in.open(fileName,ios::in);
    if(!in.is_open())
    {
        cout << "打开文件失败" << endl;
    }
    string result;
    in >> result;
    in.close();
    return result;
}
huffmanTreeNode *buildHuffmanTree(letterFrequency *lf)
{
    int n = 0;
    cout << "需要编码的字母有:";
    while(lf[n].frequency)
    {
        cout << lf[n].letter << ":" << lf[n].frequency << " ";
        n++;
    }
    cout << endl;
    huffmanTreeNode *ht = new huffmanTreeNode[2*n];
    for (int i = 1; i <= n; i++)
    {
        ht[i].letter = lf[i-1].letter;
        ht[i].frequency = lf[i-1].frequency;
        ht[i].leftchild = 0;
        ht[i].rightchild = 0;
        ht[i].parent = 0;
    }
    cout << endl;
    ht[0].frequency = INT_MAX;
    for (int j = n+1; j < 2*n; j++)
    {
        ht[j].parent = 0;
        int t1 = 0, t2 = 0;
        for(int i = 1; i < j; i++)
        {
            if(ht[i].frequency < ht[t1].frequency && !ht[i].parent)
            {
                t1 = i;
            }
        }
        for(int i = 1; i < j; i++)
        {
            if(i == t1)
            {
                continue;
            }
            if(ht[i].frequency < ht[t2].frequency && !ht[i].parent)
            {
                t2 = i;
            }
        }
        ht[j].letter = ' ';
        ht[j].frequency = ht[t2].frequency + ht[t1].frequency;
        ht[j].leftchild = t1;
        ht[j].rightchild = t2;
        ht[t1].parent = j;
        ht[t2].parent = j;
    }
    for (int i = 1; i < 2*n; i++)    
    {
        cout << ht[i].letter << ":" << ht[i].frequency << " " << ht[i].leftchild << " " << ht[i].rightchild << " " << ht[i].parent << endl;
    }
    return ht;
}
letterCode *buildLetterCode(huffmanTreeNode ht[])
{
    int n = 1;
    stack<char> st;
    while(ht[n].letter != ' ')
    {
        n++;
    }
    letterCode *result = new letterCode[n-1];
    int t, t_;
    for (int i = 1; i < n; i++)
    {
        t = ht[i].parent;
        t_ = i;
        while(t)
        {
            if(ht[t].leftchild == t_)
            {
                st.push('0');
            }
            else
            {
                st.push('1');
            }
            t_ = t;
            t = ht[t].parent;
        }
        result[i-1].letter = ht[i].letter;
        while(!st.empty())
        {
            result[i-1].code.push_back(st.top());
            st.pop();
        }
    }
    return result;
}
string letterDecode(letterCode *lc, int m)
{
    ifstream in;
    int k;
    in.open("D:\\Desktop\\a.cod", ios::in);
    vector<unsigned char> decodeStr;
    string result;
    while(!in.eof())
    {
        decodeStr.push_back(in.get());
    }
    decodeStr.pop_back();
    int x;
    for (x = 0; x < decodeStr.size(); x++)
    {
        if(decodeStr[x] != '0' && decodeStr[x] != '1')
        {
            break;
        }
    }
    if(x != decodeStr.size())
    {
        vector<unsigned char> str = decodeStr;
        int p;
        char t[9];
        decodeStr.clear();
        for (int j = 0; j < str.size(); j++)
        {
            itoa(str[j],t,2);
            for (p = 0;t[p] != '\0' ; p++);
            if(j!=str.size() - 1)
            {
                for (int i = 0; i < 8-p; i++)
                {
                    decodeStr.push_back('0');
                }
            }
            for (int i = 0; i < p; i++)
            {
                decodeStr.push_back(t[i]);
            }
        }
    }
    int n = decodeStr.size();
    for (int i = 0; i < n; )
    {
        for (int j = 0; j < m; j++)
        {
            for (k = 0; k < lc[j].code.size(); k++)
            {
                if(decodeStr[i+k] != lc[j].code[k])
                {
                    break;
                }
            }
            if(k == lc[j].code.size())
            {
                i += lc[j].code.size();
                result.push_back(lc[j].letter);
                break;
            }
        }
        
    }
    return result;
}
void compress()
{
    ifstream in("D:\\Desktop\\a.cod", ios::in);
    vector<unsigned char> str, result;
    while(!in.eof())
    {
        str.push_back(in.get());
    }
    str.pop_back();
    in.close();
    int m = str.size() / 8;
    for (int i = 0; i < m; i++)
    {
        unsigned char a = 0;
        for (int j = (i+1) * 8 - 1, t = 0; j >= i * 8; j--, t++)
        {
            a += ((str[j] - '0') * pow(2,t));
        }
        result.push_back(a);
    }
    int n = str.size() % 8;
    unsigned char a = 0;
    for (int i = m * 8 + n - 1, t = 0; i >= m * 8; i--, t++)
    {
        a += (str[i] - '0') * pow(2,t);
    }
    result.push_back(a);
    ofstream out("D:\\Desktop\\a.cod");
    for (int i = 0; i < result.size(); i++)
    {
        out << result[i];
    }
    cout << "压缩比" << str.size() << ":" << m+1 << endl;
}
int main()
{
    huffmanTreeNode *ht;
    letterCode *lc;
    letterFrequency lf[52];
    for (int i = 0; i < 26; i++)
    {
        lf[i].letter = i + 'a';
    }
    for (int i = 26; i < 52; i++)
    {
        lf[i].letter = i + 'A' - 26;
    }
    int z;
    int flag = 1;
    string str, codeStr;
    while(flag)
    {
        cout << "\
**********************************************************************\n\
* 哈夫曼编码译码器                                                   *\n\
* 1、选择需要进行编码的文件                                          *\n\
* 2、建立哈夫曼树                                                    *\n\
* 3、建立密码本并对文件编码                                          *\n\
* 4、选择需要进行解码的文件并解码                                    *\n\
* 5、按位压缩方式对文件进行压缩                                      *\n\
*                                                                    *\n\
**********************************************************************\n";
        int cho;
        cin >> cho;
        cin.get();
        switch (cho)
        {
            case 1:
            {
                str = chooseFile();
                for (int i = 0; i < 52; i++)
                {
                    lf[i].frequency = 0;
                }
                int n = str.size();
                for (int i = 0; i < n; i++)
                {
                    if(islower(str[i]))
                    {
                        lf[str[i] - 'a'].frequency++;
                    }
                    else
                    {
                        lf[str[i] - 'A' + 26].frequency++;
                    }
                    
                }
                sort(lf,lf+52,cmp);
                break;
            }
            case 2:
            {
                ht = buildHuffmanTree(lf);
                break;
            }
            case 3:
            {
                int n = 1;
                while(ht[n].letter != ' ')
                {
                    n++;
                }
                z = n-1;
                lc = buildLetterCode(ht);
                for (int i = 0; i < z; i++)
                {
                    cout << lc[i].letter << ':' << lc[i].code << endl;
                }
                int m = str.size();
                for (int i = 0; i < m; i++)
                {
                    for (int j = 0; j < n; j++)
                    {   
                        if(lc[j].letter == str[i])
                        {
                            for (int k = 0; k < lc[j].code.size(); k++)
                            {
                                codeStr.push_back(lc[j].code[k]);
                            }
                            break;
                        }
                    }
                }
                ofstream out;
                out.open("D:\\Desktop\\a.cod", ios::out);
                out << codeStr;
                out.close();
                break;
            }
            case 4:
            {
                cout << letterDecode(lc, z) << endl;
                break;
            }
            case 5:
            {
                compress();
                break;
            }
        }
    }
    return 0;
}