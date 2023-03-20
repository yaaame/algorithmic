#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void Print_vector(vector<int>&v)
{
    for(auto i:v)
        cout<<i<<" ";
    cout<<endl;
}
void permutation_1_to_n(int n,vector<int>&v,int cur=0)
{
    if(cur==n)
        Print_vector(v);
    else
    {
        for(int i=0;i<n;i++)
        {
            bool ok=1;
            for(int j=0;j<cur&&ok;j++)
                if(v[j]==i+1)
                    ok=0;
            if(ok)
            {
                v[cur]=i+1;
                permutation_1_to_n(n,v,cur+1);
            }
        }
    }
}
int main()
{
    int n=5;
    vector<int>v(n);
    permutation_1_to_n(n,v);
    return 0;
}