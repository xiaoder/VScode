#include <iostream>
using namespace std;
int MaxSubSum(int a[], int left, int right)
{
    int b[] = {0,0,0};
    int i,li,ri;
    if (left==right)
        b[2]=a[left] >0?a[left]:0;
    else
    {
        int center=(left+right)/2;
        int leftsum=MaxSubSum(a, left, center);
        int rightsum=MaxSubSum(a, center+1, right );
        int s1=0;
        int lefts=0;
        for( i=center; i>=left; i--)
        {
            lefts+=a[i];
            if (lefts>s1)
                s1=lefts;
                b[0]=i ;
        }
        int s2=0;
        int rights=0;
        for( i=center+1; i<=right; i++)
        {
            rights+=a[i];
            if (rights>s2)
                s2= rights;
                b[1]=i ;
        }
        b[2]=s1+s2;
        if(b[2]<leftsum)
            b[2]=leftsum;
        if (b[2]< rightsum)
            b[2]=rightsum;
    }
    return b;
}
int main()
{
    int n,a[100];
    cout<<"请输入数据个数：";
    cin>>n;
    for(int i=0; i<n; i++)
        cin>>a[i];
    int c=MaxSubSum(a,0,n-1);
    cout<<endl;
    for (int i=0;i<3;i++)
    {
         cout<<c[i];
    }
}
