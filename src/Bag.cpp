#include<iostream>
#include<vector>

using namespace std;

int bag_01(vector<int>&w,vector<int>&v,int cap)
{
    vector<int>dp(cap+1,0);
    for(int i=0;i<v.size();i++)
        for(int j=cap;j>=w[i];j--)
            dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
    return dp[cap];
}
int bag_complete(vector<int>&w,vector<int>&v,int cap)
{
    vector<int>dp(cap+1,0);
    for(int i=0;i<v.size();i++)
        for(int j=w[i];j<=cap;j++)
            dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
    return dp[cap];
}
int bag_mul(vector<int>&w,vector<int>&v,vector<int>&s,int cap)
{
    vector<int>dp(cap+1,0);
    for(int i=0;i<w.size();i++)
    {
        while(s[i]--)
        for(int j=cap;j>=w[i];j--)
            dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
    }
    return dp[cap];
}
int main()
{
    
    vector<int>w{30,35,10};
    vector<int>v{30,35,10};
    vector<int>s{2,2,1};
    cout<<bag_mul(w,v,s,50);
    return 0;
}