#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
long long int fast_pow(long long int a,int b)
{
    long long int res=1;
    while(b)
    {
        if(b&1)
            res*=a;
        a*=a;
        b>>=1;
    }
    return res;
}
int main()
{
    cout<<fast_pow(9,12)<<endl;
    return 0;
}
