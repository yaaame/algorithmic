#include<iostream>
#include<list>
using namespace std;
int main()
{
    list<int>l={1,2,3,4,5,6,7,5,6,9,8,1,0,2,3,6};
    for(auto i:l)
        cout<<i<<",";
    cout<<endl;
    auto ele=l.begin();
    cout<<*ele<<endl;
    return 0;
}