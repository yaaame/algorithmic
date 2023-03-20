#include<iostream>
#include<vector>
using namespace std;
bool Conclude7(int n)
{
    while(n)
    {
        if(n%10==7)
            return true;
        n/=10;
    }
    return false;
}
int main()
{
    int n;
    cin>>n;
    vector<int>v(4,0);
    for(int i=1;i<=n;i++)
    {
        if(i%7==0||Conclude7(i))
        {
            v[(i-1)%4]++;
            n++;
        }
    }
    for(int i=0;i<4;i++)
        cout<<v[i]<<endl;
}