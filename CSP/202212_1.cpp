#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int main()
{
    int n,m;
    double i,sum=0;
    cin>>n>>i;
    for(int j=0;j<=n;j++)
    {
        cin>>m;
            sum+=(m*pow(1+i,-j));
    }
    cout<<sum;
  
}