#include<vector>
#include<iostream>
using namespace std;
int main()
{
    int nums,cap;
    cin>>nums>>cap;
    int w,v;//重量、价值
    int dp[cap+1];
    for(int i=0;i<=cap;i++)
        dp[i]=0;
    for(int i=1;i<=nums;i++)
    {
        cin>>w>>v;
        for(int j=cap;j>=w;j--)
            dp[j]=max(dp[j],dp[j-w]+v);
    }
    cout<< dp[cap]<<endl;
    return 0;
}

