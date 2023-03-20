#include <iostream>
#include <map>
#include<unordered_map>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
bool twoSum(vector<int>& nums, int target,int start)
{
    unordered_map<int, int> hashtable;
    for (int i =start; i < nums.size(); ++i) 
    {
        auto it = hashtable.find(target - nums[i]);
        if (it != hashtable.end())
            return true;
        hashtable[nums[i]] = i;
    }
    return false;
}
bool threeSum(vector<int>& nums,int target) 
{
    for(int i=0;i<nums.size();i++)
    {
        if(twoSum(nums,target-nums[i],i+1))
            return true;
    }
    return false;
    
}
bool nSum(vector<int>&nums,int n,int target,int start=0)
{
    if(n==2)
        return twoSum(nums,target,start);
    for(int i=start;i<nums.size();i++)
        if(nSum(nums,n-1,target-nums[i],start+1))
            return true;
    return false;
}
bool any_Sum(vector<int>&nums,int target)
{
    int n=(int)nums.size();
    int arr[n][n];
    for(int i=0;i<n;i++)
    {
        if(nums[i]==target)
            return true;
        for(int j=i+1;j<n;j++)
        {
            arr[i][j]=nums[i]+nums[j];
            if(arr[i][j]==target)
                return true;
        }
    }
        
    for(int k=2;k<=n-1;k++)
        for(int i=0;i<n;i++)
            for(int j=i+k;j<n;j++)
            {
                arr[i][j]=arr[i][j-1]+nums[j];
                if(arr[i][j]==target)
                    return true;
            }
    return false;
}
int any_Sub(vector<bool>&bucket,vector<int>&nums)
{
    vector<int>remain;
    int count=0;
    for(int i=1;i<bucket.size();i++)
        if(!bucket[i])
            remain.push_back(i);
    for(int i=0;i<remain.size();i++)
        for(int j=1;j<bucket.size();j++)
            if(bucket[j]&&j+remain[i]<bucket.size()&&bucket[j+remain[i]])
            {
                count++;
                break;
            }
    return count;
}
int main()
{

    cout<<256*1024/4*1024<<endl;
    int n;
    cin>>n;
    
    vector<int>v(n);
    int count=0,sum=0;
    int t;
    for(int i=0;i<n;i++)
    {
        cin>>t;
        sum+=t;
        v.push_back(t);
    }
    vector<bool>bucket(sum+1,0);
    for(int i=1;i<=sum;i++)
        if(any_Sum(v,i))
        {
            count++;
            bucket[i]=true;
        }
    count+=any_Sub(bucket,v);
    cout<<count<<endl;
    return 0;
}