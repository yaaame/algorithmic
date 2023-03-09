#include<iostream>
#include<stack>
#include<queue>
#include<vector>
using namespace  std;
vector<int> sortedSquares(vector<int>& nums)
{
    stack<int>s;//保存负数
    queue<int>q;//保存正数
    int n=(int)nums.size();
    for(int i=0;i<n;i++)
    {
        if(nums[i]>0)
            q.push(nums[i]);//正数进队列
        else
            s.push(nums[i]);//负数进栈
    }
    vector<int>ans;
    while(!q.empty()&&!s.empty())
    {
        int a=q.front()*q.front();//正数平方
        int b=s.top()*s.top();//负数平方
        if(a<b)//正数小，队列出
        {
            ans.push_back(a);
            q.pop();
        }
        else
        {
            ans.push_back(b);
            s.pop();
        }
    }
    while(!q.empty())
    {
        int a=q.front()*q.front();//正数平方
        ans.push_back(a);
        q.pop();
    }
    while(!s.empty())
    {
        int b=s.top()*s.top();//负数平方
        ans.push_back(b);
        s.pop();
    }
    return ans;
    
}
vector<int> sortedSquares1(vector<int>& nums)
{
    int n=(int)nums.size();
    int i=0,j;
    for(;i<n;i++)
        if(nums[i]>=0)
            break;
    j=i-1;
    vector<int>ans;
    while(j>=0&&i<n)
    {
        int a=nums[i]*nums[i];
        int b=nums[j]*nums[j];
        if(a<b)
        {
            ans.push_back(a);
            i++;
        }
        else
        {
            ans.push_back(b);
            j--;
        }
    }
    while(j>=0)
    {
        ans.push_back(nums[j]*nums[j]);
        j--;
    }
    while(i<n)
    {
        ans.push_back(nums[i]*nums[i]);
        i++;
    }
    return ans;
}
vector<int>sortedSquares2(vector<int>&nums)
{
    int n=(int)nums.size();
    int i=0,j=n-1,k=n-1;
    vector<int>ans(n);
    while(i<=j)
    {
        if(nums[i]*nums[i]<nums[j]*nums[j])
        {
            ans[k--]=nums[j]*nums[j];
            j--;
        }
        else
        {
            ans[k--]=nums[i]*nums[i];
            i++;
        }
    }
    return ans;
}
int main()
{
    vector<int>nums{-7,-3,2,3,11};
    vector<int>ans= sortedSquares2(nums);
    for(auto i:ans)
        cout<<i<<" ";
    return 0;
}