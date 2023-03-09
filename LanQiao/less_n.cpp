#include<iostream>
using namespace  std;
int main()
{
    int ans=0;
    int n;
    cin>>n;
    for(int i=1;i<n;i++)
        if(2*((i*i)%n)<n)
            ans++;
    cout<<ans;
}