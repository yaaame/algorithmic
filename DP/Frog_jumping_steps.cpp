#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n=100;
    int MOD = 1000000007;
    int a=1,b=1,t=0;
    for(int i=2;i<=n;i++)
    {
        t=a;
        a=(a+b)%MOD;
        b=t;
    }
    cout<<a<<endl;
    return 0;
}