#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n,v;
    cin>>n;
    vector<int>p{1,3,5,7,9,10,11,14,15,17};
    vector<int>dp(n+1,0);
    for(int i=0;i<10&&i<n;i++)
    {
        cin>>v;
        v-=p[i];
        for(int j=i+1;j<=n;j++)
            dp[j]=max(dp[j],dp[j-(i+1)]+v);
    }
    cout<<dp[n]<<endl;
    return 0;
}