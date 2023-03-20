#include<iostream>
#include<vector>
#define N 100
using namespace std;
class UF_set
{
public:
    vector<int>rank;
    vector<int>pre;
    UF_set()
    {
        rank.resize(N,1);
        pre.resize(N);
        for(int i=0;i<N;i++)
            pre[i]=i;
    }
    int Find(int x)
    {
        if(x==pre[x])
            return x;
        return pre[x]=Find(pre[x]);
    }
    bool Union(int x,int y)
    {
        x=Find(x);
        y=Find(y);
        if(x==y)
            return false;
        if(rank[x]==rank[y])
        {
            rank[y]++;
            pre[x]=y;
        }
        else
            rank[x]>rank[y]?pre[y]=x:pre[x]=y;
        return true;
    }
    bool Same_Set(int x,int y)
    {
        x=Find(x);
        y=Find(y);
        if(x==y)
            return true;
        return false;
    }
};
int main()
{
    UF_set u;
    cout<<u.Find(1)<<endl;
    u.Union(1,2);
    u.Union(1,3);
    u.Union(1,4);
    u.Union(1,5);
    cout<<u.Find(5)<<endl;
    cout<<u.Find(1)<<endl;
    cout<<u.Find(3)<<endl;
    cout<<u.Find(4)<<endl;
    cout<<"fds"<<u.Same_Set(1,6)<<endl;
    cout<<"fds"<<u.Same_Set(1,2)<<endl;
    cout<<"fds"<<u.Same_Set(3,5)<<endl;
    return 0;
}