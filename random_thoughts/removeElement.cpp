#include<iostream>
#include<vector>
using namespace std;
int removeElement(vector<int>& nums, int val)
{
    for(int i=0;i<nums.size();i++)
    {
        if(nums[i]==val)
        {
            swap(nums[i],nums.back());
            nums.pop_back();
            i--;
        }
    }
    return nums.size();
}
int main()
{
    vector<int>v{1,5,6,8,6,5,4,5,2};
    int n= removeElement(v,5);
    
}
