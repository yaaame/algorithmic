#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
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
            r=mid-1;
    }
    return false;
}
float fun()
{
    return 3;
}
class P
{
public:
    void operator ()(int val)
    {
       cout<<val<<',';
    }
};
int main()
{
    vector<int>v{1,5,9,7,6,1,5,3,2,4,86,3};
    return 0;
}