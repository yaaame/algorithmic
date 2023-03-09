#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n,m,a,b;
    cin>>n>>m;
    vector<int>v(n+1,0);
    for(int i=0;i<m;i++)
    {
        cin>>a>>b;
        for(int j=a;j<=b;j++)
            v[j]++;
    }
    int flag=1;
    for(int i=1;i<=n;i++)
        if(v[i]==0||v[i]>=2)
        {
            cout<<i<<" "<<v[i]<<endl;
            flag=0;
            break;
        }
    if(flag)
        cout<<"OK"<<endl;
    return 0;
}