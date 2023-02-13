#include <iostream>
#include <map>
#include<unordered_map>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
vector<int> twoSum(vector<int>& nums, int target,int start) {
    unordered_map<int, int> hashtable;
    for (int i = start+1; i < nums.size(); ++i) {
        auto it = hashtable.find(target - nums[i]);
        if (it != hashtable.end()) {
            return {it->first, nums[i]};
        }
        hashtable[nums[i]] = i;
    }
    return {};
}
vector<vector<int>> threeSum(vector<int>& nums) 
{
    multiset<int>copy(nums.begin(),nums.end());
    vector<vector<int>>ans;
    vector<int>tt;
    vector<int>t;
    tt.assign(copy.begin(),copy.end());
    int n=(int)tt.size();
    for(int i=0;i<n;i++)
    {
        if(i<n-1&&tt[i]==tt[i+1])
        {
            t=twoSum(tt,-(tt[i]+tt[i+1]),i);
            if(!t.empty())
            {
                t.push_back(tt[i]);
                ans.push_back(t);
            }
            continue;
        }
        t=twoSum(tt,-tt[i],i);
        if(!t.empty())
        {
            t.push_back(tt[i]);
            ans.push_back(t);
        }
    }
    return ans;
}
int main()
{
    vector<int>v{-1,0,1,2,-1,-4};
    vector<vector<int>>ans=threeSum(v);
    vector<int>v1{1,2};
    vector<int>v2{1,2};
    cout<<(v1==v2)<<endl;
}