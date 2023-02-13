#include<iostream>
#include<vector>
using namespace std;
int rob(vector<int>& nums) 
{
    int dp[110];
    int n=(int)nums.size();
    dp[0]=nums[0];
    dp[1]=max(nums[0],nums[1]);
    for(int i=2;i<n;i++)
        dp[i]=max(dp[i-1],dp[i-2]+nums[i]);
    return dp[n-1];
}
int main()
{
    vector<int>v{2,7,9,3,1};
    cout<<rob(v)<<endl;
    cout<<-3%2<<endl;
    return 3;
}