#include<iostream>
#include<vector>
#include<algorithm>
#include<bitset>
using namespace std;
typedef unsigned long long int ULLI;
vector<int> HDAmul(vector<int>v1, vector<int> v2)
{
    vector<int>vt(v1.size()+v2.size());
    for (int i = 0; i < v1.size(); i++)
        for (int j = 0; j < v2.size(); j++)
        {
            vt[i + j] += v1[i] * v2[j];
            vt[i + j+1] +=vt[i+j]/10;
            vt[i + j] %= 10;
        }
    while (vt.size() > 1 && vt.back() == 0)
        vt.pop_back();
    return vt;
}
void aaa()
{
    vector<int>init={1};
    for(int i=1;i<=20;i++)
    {
        vector<int>t={i};
        init= HDAmul(init,t);
    }
    for_each(init.begin(),init.end(),[](int value){cout<<value;});
    cout<<endl;
}
int main()
{
    aaa();
    cout<<endl;
    ULLI la=1;
    ULLI lb=0;
    ULLI L32=0x00000000FFFFFFFF;
   for(int i=1;i<=21;i++)
   {
       // : 0000 XXXX
       //la : e a
       //lb : d c
       ULLI a=la&L32;
       ULLI e=la>>32;
       ULLI d=lb>>32;
       ULLI c=lb&L32;
       a*=i;//低位乘  a :      0001 1011 
       e*=i;//中位乘  e : 0101 1101
       e+=a>>32;//中位加上低位进位 e : 0101 1110
       a&=L32;//  a : 0000 1011
       d*=i; //                 d : 0000 0010
       
       d+=e>>32;// d : 0000 0111
       c=e&L32;// c : 0000 1110
       e=c;//   e : 0000 1110
       d<<=32; // d : 0111 0000
       la=(e<<32)+a;
       lb=d+c;
   }
   bitset<32>a(lb>>32);
   bitset<32>b(lb&L32);
   bitset<32>d(la&L32);
    for(int i=31;~i;i--)
    {
        cout<<a[i];
        if((i)%4==0)
            cout<<" ";
    }
    cout<<endl;
    for(int i=31;~i;i--)
    {
        cout<<b[i];
        if((i)%4==0)
            cout<<" ";
    }
    cout<<endl;
    for(int i=31;~i;i--)
    {
        cout<<d[i];
        if((i)%4==0)
            cout<<" ";
    }
    cout<<endl;
   return 0;
}