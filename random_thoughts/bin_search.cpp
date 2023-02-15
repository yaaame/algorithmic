#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool bin_search(const vector<int>&v,int value)
{
    vector<int>copy(v);
    sort(copy.begin(),copy.end());
    int l=0,r=(int)copy.size()-1;
    while(l<r)
    {
        int mid=(l+r)/2;
        if(copy[mid]==value)
            return true;
        else if(copy[mid]>value)
            l=mid+1;
        else
            r=mid;
    }
    return false;
}
int main()
{
    vector<int>v{1,5,9,7,6,1,5,3,2,4,86,3};
    cout<<bin_search(v,4)<<endl;
    return 0;
}