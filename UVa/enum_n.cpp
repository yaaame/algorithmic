#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
void Print_subset(vector<int>v,vector<int>&a,int cur)
{
    for_each(a.begin(),a.begin()+cur,[](int value){cout<<value<<" ";});
    cout<<endl;
    int s=cur;
    for(int i=s;i<v.size();i++)
    {
        a[cur]=v[i];
        Print_subset(v,a,cur+1);
    }
}
void  enum_print(vector<int>a,int cur)
{
    if(cur==a.size())
    {
        for_each(a.begin(),a.end(),[](int value){cout<<value;});
        cout<<endl;
    }
    else
        for(int i=0;i<a.size();i++)
        {
            int ok=1;
            for(int j=0;j<cur&&ok;j++)
                if(a[j]==i+1)
                    ok=0;
            if(ok) {
                a[cur] = i + 1;
                enum_print(a, cur + 1);
            }
        }
}
void STL_enum(vector<int>v)
{
    sort(v.begin(),v.end());
    do
    {
        for_each(v.begin(),v.end(),[](int value){cout<<value;});
        cout<<endl;
    }while(next_permutation(v.begin(),v.end()));
    next_permutation(v.begin(),v.end());
}
void Bin_subset(vector<int>v,int s)
{
    for(int i=0;i<v.size();i++)
    {
        if(s&(1<<i))
            cout<<v[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    vector<int>a(3);
    vector<int>v{1,2,5};
    //Print_subset(v,a,0);
    for(int i=0;i<(1<<v.size());i++)
        Bin_subset(v,i);
    
    return 0;
}