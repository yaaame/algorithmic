#include<iostream>
#include<cmath>
using namespace std;
int a[8][8],b[8][8];
double c[8][8];
int t,num;
double pi=acos(-1);
double Mij(int i,int j)
{
    int u,v;
    double au,av;
    double sum=0;
    for(u=0;u<=7;u++)
    {
        for(v=0;v<=7;v++)
        {
            if(u==0)
                au=sqrt(0.5);
            else
                au=1;
            if(v==0)
                av=sqrt(0.5);
            else
                av=1;
            sum+=au*av*b[u][v]*cos(pi/8*u*(i+0.5))*cos(pi/8*v*(j+0.5));
        }
    }
    return sum/4;
}
void print()
{
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
            cout<<b[i][j]<<" ";
        cout<<endl;
    }
}
void cprint()
{
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
            cout<<floor(c[i][j]+128.5)<<" ";
        cout<<endl;
    }
}
int main()
{
    for(int i=0;i<8;i++)
        for(int j=0;j<8;j++)
            cin>>a[i][j];
    cin>>num>>t;
    int count=1;
    int i,j;
    i=0;
    j=0;
    int d=0;
    if(num!=0)
        cin>>b[0][0];
    while(count<num)
    {
        if(d==0)
            cin>>b[i][++j];
        if(d==1)
            cin>>b[++i][--j];
        if(d==2)
            cin>>b[++i][j];
        if(d==3)
            cin>>b[--i][++j];
        if((i==0)||(i!=7&&j==0))
            d=(d+1)%4;
        if(i==7||j==7)
            d=(d+3)%4;
        count++;
    }
    if(t==0)
    {
        print();
        return 0;
    }
    for(int i=0;i<8;i++)
        for(int j=0;j<8;j++)
            b[i][j]*=a[i][j];
    if(t==1)
    {
        print();
        return 0;
    }
    if(t==2)
    {
        for(int i=0;i<8;i++)
            for(int j=0;j<8;j++)
                c[i][j]=Mij(i,j);
    }
    cprint();
    return 0;
}