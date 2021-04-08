#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <fstream>
using namespace std;
typedef struct num_op
{
    float num;
    char op;
} num_op;
vector<char> readIn()
{
    vector<char> result;
    cout << "请输入算数表达式:";
    char ch = cin.get();
    while (ch != '\n')
    {
        result.push_back(ch);
        ch = cin.get();
    }
    return result;
}
float getNumber(vector<char> &t)
{
    int i = 0;
    int flag = 1;
    float m = 0.1;
    int n = t.size();
    float result = 0;
    for (; i < n; i++)
    {
        if (t[i] >= '0' && t[i] <= '9' && flag)
        {
            result = result * 10 + t[i] - '0';
        }
        else if (t[i] == '.')
        {
            flag = 0;
        }
        else if (t[i] >= '0' && t[i] <= '9' && !flag)
        {
            result = result + (t[i] - '0') * m;
            m /= 10;
        }
        else
        {
            break;
        }
    }
    t.erase(t.begin(), t.begin() + i);
    return result;
}
bool parenthesesMatching(vector<char> &t)
{
    int n = t.size();
    stack<char> st;
    for (int i = 0; i < n; i++)
    {
        if (t[i] == '(')
        {
            st.push('(');
        }
        else if (t[i] == ')')
        {
            if (st.empty() && st.top() != '(')
            {
                return false;
            }
            st.pop();
        }
    }
    if (st.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}
queue<num_op> nifixToSuffix()
{
    vector<char> nifix;
    cout << "1.输入表达式\n2.选择文件\n";
    int x;
    cin >> x;
    cin.get();
    if (x == 1)
    {
        nifix = readIn();
    }
    else
    {
        cout << "请输入文件路径:";
        string filename;
        cin >> filename;
        ifstream in(filename, ios::in);
        char ch = in.get();
        while (!in.eof())
        {
            nifix.push_back(ch);
            ch = in.get();
        }
    }
    queue<num_op> result;
    if (!parenthesesMatching(nifix))
    {
        nifix.clear();
        cout << "括号不匹配";
        return result;
    }
    stack<char> op;

    num_op t;
    while (!nifix.empty())
    {
        if (nifix[0] == ' ')
        {
            nifix.erase(nifix.begin(), nifix.begin() + 1);
        }
        else if (nifix[0] == '(')
        {
            op.push('(');
            nifix.erase(nifix.begin(), nifix.begin() + 1);
        }
        else if (nifix[0] == ')')
        {
            while (op.top() != '(')
            {
                t.num = 0;
                t.op = op.top();
                result.push(t);
                op.pop();
            }
            op.pop();
            nifix.erase(nifix.begin(), nifix.begin() + 1);
        }
        else if (nifix[0] == '+' || nifix[0] == '-')
        {
            if (!op.empty())
            {
                while (op.top() == '+' || op.top() == '-' || op.top() == '*' || op.top() == '/' || op.top() == '^')
                {
                    t.num = 0;
                    t.op = op.top();
                    result.push(t);
                    op.pop();
                }
            }
            op.push(nifix[0]);
            nifix.erase(nifix.begin(), nifix.begin() + 1);
        }
        else if (nifix[0] == '*' || nifix[0] == '/')
        {
            if (!op.empty())
            {
                while (op.top() == '*' || op.top() == '/' || op.top() == '^')
                {
                    t.num = 0;
                    t.op = op.top();
                    result.push(t);
                    op.pop();
                }
            }
            op.push(nifix[0]);
            nifix.erase(nifix.begin(), nifix.begin() + 1);
        }
        else if (nifix[0] == '^')
        {
            if (!op.empty())
            {
                while (op.top() == '^')
                {
                    t.num = 0;
                    t.op = op.top();
                    result.push(t);
                    op.pop();
                }
            }
            op.push(nifix[0]);
            nifix.erase(nifix.begin(), nifix.begin() + 1);
        }
        else
        {
            t.num = getNumber(nifix);
            if (!op.empty() && op.top() == '/' && t.num < 1e-6)
            {
                cout << "除零异常！";
                exit(0);
            }
            result.push(t);
        }
    }
    while (!op.empty())
    {
        t.num = 0;
        t.op = op.top();
        result.push(t);
        op.pop();
    }
    return result;
}
float suffixEvaluation()
{
    vector<char> suffix;
    cout << "1.输入表达式\n2.选择文件\n";
    int x;
    cin >> x;
    cin.get();
    if (x == 1)
    {
        suffix = readIn();
    }
    else
    {
        cout << "请输入文件路径:";
        string filename;
        cin >> filename;
        ifstream in(filename, ios::in);
        char ch = in.get();
        while (!in.eof())
        {
            suffix.push_back(ch);
            ch = in.get();
        }
    }
    stack<float> num;
    float t1, t2;
    while (!suffix.empty())
    {
        if (suffix[0] == ' ')
        {
            suffix.erase(suffix.begin(), suffix.begin() + 1);
        }
        else if (suffix[0] == '+')
        {
            t1 = num.top();
            num.pop();
            t2 = num.top();
            num.pop();
            num.push(t2 + t1);
            suffix.erase(suffix.begin(), suffix.begin() + 1);
        }
        else if (suffix[0] == '-')
        {
            t1 = num.top();
            num.pop();
            t2 = num.top();
            num.pop();
            num.push(t2 - t1);
            suffix.erase(suffix.begin(), suffix.begin() + 1);
        }
        else if (suffix[0] == '*')
        {
            t1 = num.top();
            num.pop();
            t2 = num.top();
            num.pop();
            num.push(t2 * t1);
            suffix.erase(suffix.begin(), suffix.begin() + 1);
        }
        else if (suffix[0] == '/')
        {
            t1 = num.top();
            num.pop();
            if (t1 < 1e-6)
            {
                cout << "除零异常！";
                exit(0);
            }
            t2 = num.top();
            num.pop();
            num.push(t2 / t1);
            suffix.erase(suffix.begin(), suffix.begin() + 1);
        }
        else if (suffix[0] == '^')
        {
            t1 = num.top();
            num.pop();
            t2 = num.top();
            num.pop();
            num.push(pow(t2, t1));
            suffix.erase(suffix.begin(), suffix.begin() + 1);
        }
        else
        {
            num.push(getNumber(suffix));
        }
    }

    return num.top();
}
float evaluation(float num1, char op, float num2)
{
    switch (op)
    {
    case '+':
        return num1 + num2;
        break;
    case '-':
        return num1 - num2;
        break;
    case '*':
        return num1 * num2;
        break;
    case '/':
        return num1 / num2;
        break;
    case '^':
        return pow(num1, num2);
    default:
        return 0;
        break;
    }
}
float nifixEvaluation()
{
    float result = 0;
    vector<char> nifix;
    cout << "1.输入表达式\n2.选择文件\n";
    int x;
    cin >> x;
    cin.get();
    if (x == 1)
    {
        nifix = readIn();
    }
    else
    {
        cout << "请输入文件路径:";
        string filename;
        cin >> filename;
        ifstream in(filename, ios::in);
        char ch = in.get();
        while (!in.eof())
        {
            nifix.push_back(ch);
            ch = in.get();
        }
    }
    if (!parenthesesMatching(nifix))
    {
        nifix.clear();
        cout << "括号不匹配";
        return result;
    }
    stack<char> op;
    stack<float> num;
    float t1, t2;
    while (!nifix.empty())
    {
        if (nifix[0] == ' ')
        {
            nifix.erase(nifix.begin(), nifix.begin() + 1);
        }
        else if (nifix[0] == '(')
        {
            op.push('(');
            nifix.erase(nifix.begin(), nifix.begin() + 1);
        }
        else if (nifix[0] == ')')
        {
            while (op.top() != '(')
            {
                t1 = num.top();
                num.pop();
                t2 = num.top();
                num.pop();
                num.push(evaluation(t2, op.top(), t1));
                op.pop();
            }
            op.pop();
            nifix.erase(nifix.begin(), nifix.begin() + 1);
        }
        else if (nifix[0] == '+' || nifix[0] == '-')
        {
            if (!op.empty())
            {
                while (op.top() == '+' || op.top() == '-' || op.top() == '*' || op.top() == '/' || op.top() == '^')
                {
                    t1 = num.top();
                    num.pop();
                    t2 = num.top();
                    num.pop();
                    num.push(evaluation(t2, op.top(), t1));
                    op.pop();
                }
            }
            op.push(nifix[0]);
            nifix.erase(nifix.begin(), nifix.begin() + 1);
        }
        else if (nifix[0] == '*' || nifix[0] == '/')
        {
            if (!op.empty())
            {
                while (op.top() == '*' || op.top() == '/' || op.top() == '^')
                {
                    t1 = num.top();
                    num.pop();
                    t2 = num.top();
                    num.pop();
                    num.push(evaluation(t2, op.top(), t1));
                    op.pop();
                }
            }
            op.push(nifix[0]);
            nifix.erase(nifix.begin(), nifix.begin() + 1);
        }
        else if (nifix[0] == '^')
        {
            if (!op.empty())
            {
                while (op.top() == '^')
                {
                    t1 = num.top();
                    num.pop();
                    t2 = num.top();
                    num.pop();
                    num.push(evaluation(t2, op.top(), t1));
                    op.pop();
                }
            }
            op.push(nifix[0]);
            nifix.erase(nifix.begin(), nifix.begin() + 1);
        }
        else
        {
            num.push(getNumber(nifix));
            if (!op.empty() && op.top() == '/' && num.top() < 1e-6)
            {
                cout << "除零异常！";
                exit(0);
            }
        }
    }
    while (!op.empty())
    {
        t1 = num.top();
        num.pop();
        t2 = num.top();
        num.pop();
        num.push(evaluation(t2, op.top(), t1));
        op.pop();
    }
    return num.top();
}
int main()
{
    int flag = 1;
    while (flag)
    {
        cout << "\
------------------------------------------------------\n\
 表达式求值\n\
1. 中缀表达式到后缀表达式的转换\n\
2. 后缀表达式的计算\n\
3. 中缀表达式的计算\n\
4. 退出\n\
-------------------------------------------------------\n";
        int cho;
        cin >> cho;
        cin.get();
        switch (cho)
        {
        case 1:
        {
            queue<num_op> t_, t = nifixToSuffix();
            while (!t.empty())
            {
                if (t.front().num < 1e-6)
                {
                    cout << t.front().op << " ";
                }
                else
                {
                    cout << t.front().num << " ";
                }
                t_.push(t.front());
                t.pop();
            }
            cout << endl;
            cout << "是否将结果存入文件？\n1.是\n2.否\n";
            int x;
            cin >> x;
            cin.get();
            if (x == 1)
            {
                cout << "请输入文件路径:";
                string filename;
                cin >> filename;
                ofstream out(filename, ios::out);
                while (!t_.empty())
                {
                    if (t_.front().num < 1e-6)
                    {
                        out << t_.front().op << " ";
                    }
                    else
                    {
                        out << t_.front().num << " ";
                    }
                    t_.pop();
                }
            }
            break;
        }
        case 2:
        {
            cout << suffixEvaluation() << endl;
            break;
        }
        case 3:
        {
            cout << nifixEvaluation() << endl;
            break;
        }
        case 4:
        {
            flag = 0;
            break;
        }
        }
    }
    return 0;
}