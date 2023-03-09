#include <iostream>
#include <map>
#include<unordered_map>
#include<vector>
using namespace std;
vector<int> twoSum(vector<int>& nums, int target)
{
    unordered_map<int,int>hashmap;
    int n=(int)nums.size();
    for(int i=n-1;~i;i--)
    {
        if(hashmap.find(target-nums[i])!=hashmap.end())
            return {i,hashmap[target-nums[i]]};
        hashmap[nums[i]]=i;

    }
    return {};
}
int main()
{
    vector<int> v{2,7,11,15};
    vector<int>ans=twoSum(v,9);
    cout << "fads" << endl;
    for (auto i : ans)
        cout << i << ",";
    cout << endl;
    return 0;
}