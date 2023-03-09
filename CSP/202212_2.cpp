#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class node
{
public:
    int e=1;
    int l=0;
    int day=0;
};
int main()
{
    int n,m,de,td;
    cin>>n>>m;
    node course[m+1];
    vector<int>dep;
    vector<int>time_day;
    for(int i=1;i<=m;i++)
    {
        cin>>de;
        dep.push_back(de);
    }
    for(int i=1;i<=m;i++)
    {
        cin>>td;
        time_day.push_back(td);
    }
    for(int i=1;i<=m;i++)
    {
        course[i].day=time_day[i-1];
        course[i].e=dep[i-1]==0?1:course[dep[i-1]].e+course[dep[i-1]].day;
    }
    for(int j=1;j<=m;j++)
        cout<<course[j].e<<" ";
    cout<<endl;
    bool flag=true;
    for(int i=1;i<=m;i++)
    {
        course[i].l=n+1-course[i].day;
        if(course[i].l<course[i].e)
            flag=false;
    }
    for(int i=m;i>=1&&flag;i--)
    {
        if(course[i].l<course[dep[i-1]].day+course[dep[i-1]].e)
            flag=false;
    }
    if(flag)
        for(int j=1;j<=m;j++)
            cout<<course[j].l<<" ";
    return 0;
}