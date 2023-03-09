#include<iostream>
#include<vector>
using namespace std;
int main()
{
    long long int sum=0;
    int n;
    cin>>n;
    vector<int>v(n);
    vector<long long int>pre_sum(n);
    int m;
    vector<vector<int>>vv;
    for(int i=0;i<n;i++)
    {
        cin>>m;
        v[i]=m;
        if(i==0)
            pre_sum[i]=m;
        else
            pre_sum[i]=m+pre_sum[i-1];
    }
    for(int i=0;i<n;i++)
        sum+=v[i]*(pre_sum[n-1]-pre_sum[i]);
    cout<<sum;
}