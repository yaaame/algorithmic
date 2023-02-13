#include<iostream >
using namespace  std;
int main()
{
    int n=100;
    int count=0;
    while(n)
    {
        if(n&1)
            n--;
        else
            n>>=1;
        count++;
    }
    cout<<count<<endl;
    n=100;
    int arr[1000]{0};
    for(int i=1;i<=n;i++)
    {
        if(i&1)
            arr[i]=arr[i-1]+1;
        else
            arr[i]=arr[i/2]+1;
    }
    cout<<arr[n]<<endl;
    return 2;
}