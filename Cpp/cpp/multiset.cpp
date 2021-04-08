#include <iostream>
#include <cstring>
#include <set>
using namespace std;
int main()
{
    multiset<int> st;
    int aa[10] = {1, 14, 18, 1, 555, 8, 32, 88, 55, 42};
    for (int i = 0; i < 10; i++)
    {
        st.insert(aa[i]);
    }
    multiset<int>::iterator i;
    for (i = st.begin(); i != st.end(); i++)
    {
        cout << *i << ",";
    }
    cout << endl;
    i = st.find(22);
    if(i == st.end())
    {
        cout << "not find" << endl;
    }
    else
    {
        cout << "find:" << *i << endl;
    }
    i = st.lower_bound(13);
    cout << *i << endl;
    i = st.upper_bound(8);
    cout << *i << endl;
    st.erase(i);
    for (i = st.begin(); i != st.end(); i++)
    {
        cout << *i << ",";
    }
    return 0;
}