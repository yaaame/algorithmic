#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    int t;
    for(int i=0;i<n;i++)
    {
        cin>>t;
        if(i==0)
            v[i]=t;
        else
            v[i]=v[i-1]*t;
    }
    for(int i=n-1;~i;i--)
        if(v[i]>0)
        {
            cout<<v[i]<<endl;
            break;
        }
    return 0;
}