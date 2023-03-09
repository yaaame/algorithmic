#include<iostream>
#include<map>
#include<vector>
#include<string>
using namespace std;
int main()
{
    int x=9;
    vector<int>prime;
    for(int i=2;i*i<=x;i++)
        while(x%i==0)
        {
            prime.push_back(i);
            x/=i;
        }
    if(x>1)
        prime.push_back(x);
    map<int,int>hash;
    for(auto i:prime)
        hash[i]++;
    bool flag=true;
    if(hash.size()==1&&hash.begin()->second>=2)
        cout<<"yes";
    else
    {
        vector<int>bucket(65,0);
        for(auto i:hash)
        {
            if(i.second<2)
            {
                cout<<"no"<<endl;
                flag=false;
                break;
            }
            else
            {
                if(bucket[i.second]==0)
                    bucket[i.second]=i.first;
                else
                    bucket[i.second]*=i.first;
            }
        }
        int count=0;
        for(auto i:bucket)
            if(i!=0)
                count++;
        if(count>2&&flag)
            cout<<"no";
        else if(count<=2&&flag)
            cout<<"yes";
          
        
    }
    return 0;
}