#include<iostream>

using namespace std;
/*
 * 输入k
 * 找到x>=y,x,y为整数且 1/k=1/x + 1/y
 */

int main()
{
    int k,count=0;
    cin>>k;
    for(int y=k+1;y<=2*k;y++)
        if((double)(k*y)/(y-k)==(k*y)/(y-k))
        {
            cout<<(k*y)/(y-k)<<" "<<y<<endl;
            count++;
        }
    cout<<endl<<count<<endl;
}