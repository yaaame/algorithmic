#include<iostream>
using namespace std;
int main()
{
    int n=737;
    bool flag=true;
    int i=2;
    for(;i*i<=n;i++)
            if(n%i==0)
            {
                flag=false;
                break;
            }
    if(flag)
        cout<<"yes";
    else
    {
        cout<<i<<endl;
        cout<<n%i<<endl;
        cout<<"no";
    }
    return 0;
}