#include<iostream>
#include<vector>
using namespace std;
int rob(vector<int>& nums) 
{
    int a,b,c,n=(int)nums.size();
    a=nums[0];
    b=max(a,nums[1]);
    for(int i=2;i<n;i++)
    {
        c=max(b,a+nums[i]);
        a=b;
        b=c;
    }
    return c;
}
int main()
{
    vector<int>v{2,1,1,2};
    cout<<rob(v)<<endl;
    return 3;
}