#include<vector>
#include<iostream>
using namespace std;
int main()
{
    int n,x,p;
    cin>>n>>x;
    int sum=0;
    vector<int>price;
    for(int i=0;i<n;i++)
    {
        cin>>p;
        price.push_back(p);
        sum+=p;
    }
    int cap=sum-x;
    vector<int>dp(cap+1,0);
    for(int i=0;i<n;i++)
        for(int j=cap;j>=price[i];j--)
                dp[j]=max(dp[j],dp[j-price[i]]+price[i]);
    cout<<sum-dp[cap]<<endl;
    return 0;
}