#include<vector>
#include<iostream>
using namespace std;
int bag_01(vector<int>&v,int num)
{   
    int sum=0;
    for(auto i:v)
        sum+=i;
    int n=sum-num;
    int arr[3000]{0};
    for(int i = 0; i < v.size(); i++)
    {
        for (int j = n; j >= 0; j--)
        {
            if (v[i] <= j)
                arr[j] = arr[j - v[i]] +
                        v[i] > arr[j] ? arr[j -v[i] ] + v[i]  : arr[j];
        }
    }
    return sum-arr[n];
}
int main()
{
    vector<int>v{15,40,30};
    cout<<bag_01(v,60)<<endl;
    return 1;
}