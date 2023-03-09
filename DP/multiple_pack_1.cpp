#include <iostream>
#include<vector>
using namespace std;
int dp[110];
int main()
{
    int nums,cap;
    cin>>nums>>cap;
    int w,v,s;//重量、价值
    for(int i=1;i<=nums;i++)
    {
        cin>>w>>v>>s;
        while(s--)
            for(int j=cap;j>=w;j--)
                dp[j]=max(dp[j],dp[j-w]+v);
    }
    cout<<dp[cap];
    return 0;
}

