#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int m,s;//位数，数
    cin>>m>>s;
    if(s>m*9||(m>1&&s==0))
    //无解情况，数位和>位数*9或一堆零
    {
        cout<<"-1 -1"<<endl;
        return 0;
    }
    //有解情况，设计两个数组
    // 最小值数组开头存一个1，s-1存到最后一位，如果最后一位>9,则最后一位保留9，其余数字往前一位进
    // 最大值数开头存s，如果开头>9,则开头保留9，其余数字往后一位进
    vector<int>min(m,0);
    vector<int>max(m,0);
    min[0]=1;
    min[m-1]=m==1?s:s-1;//判断m是不是个位数
    max[0]=s;
    int i=0,j=m-1;
    while(max[i]>9)
    {
        max[i+1]+=max[i]-9;
        max[i++]=9;
    }
    while(min[j]>9)
    {
        min[j-1]+=min[j]-9;
        min[j--]=9;
    }
    for_each(min.begin(),min.end(),[](int val){cout<<val;});
    cout<<" ";
    for_each(max.begin(),max.end(),[](int val){cout<<val;});
    return 0;
}
