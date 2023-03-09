#include<iostream>
#include<vector>
using namespace std;
int minSubArrayLen(int target, vector<int>& nums) 
{
    int ans=INT_MAX;
    int n=(int)nums.size();
    vector<int>prefix_sum(n);
    prefix_sum[0]=nums[0];
    for(int i=1;i<n;i++)
        prefix_sum[i]=prefix_sum[i-1]+nums[i];
    int i=1,j=0;
    while(j<n&&prefix_sum[j]<target)
        j++;
    if(j==n)
        return 0;
    else
        ans=min(ans,j+1);
    if(j==0)
        j=1;
    while(i<=j&&j<n)
    {
        if(prefix_sum[j]-prefix_sum[i-1]<target)
            j++;
        else
        {
            ans=min(ans,j-i+1);
            i++;
        }
    }
    return ans;
}
int minSubArrayLen1(int target, vector<int>& nums)
{
    int ans=INT_MAX;
    int n=(int)nums.size();
    int t_sum=nums[0];
    int i=0,j=0;
    while(i<=j&&j<n)
    {
        if(t_sum<target)
        {
            j++;
            if(j==n)
                break;
            t_sum+=nums[j];
        }
        else
        {
            ans=min(ans,j-i-1);
            t_sum-=nums[i];
            i++;
        }
    }
    if(ans==INT_MAX)
        return 0;
    return ans;
}
int main()
{
    vector<int>v{2,3,1,2,4,3};
    cout<<minSubArrayLen1(7,v)<<endl;
    return 0;
}