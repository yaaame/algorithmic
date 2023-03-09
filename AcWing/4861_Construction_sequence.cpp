#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
int main()
{
    int T,n;
    cin>>T;
    while(T--)
    {
        cin>>n;
        vector<int>v;
        int cnt=0;
        while(n)
        {
            v.push_back(n%10);
            if(n%10)
                cnt++;
            n/=10;
        }
        cout<<cnt<<endl;
        for(int i=0;i<v.size();i++)
            if(v[i])
                cout<<pow(10,i)*v[i]<<" ";
        cout<<endl;
        cnt=0;
        v.clear();
    }
    return 0;
}