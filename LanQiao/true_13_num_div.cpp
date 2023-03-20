#include<iostream>
#include<map>
#include<vector>
#include<string>
using namespace std;
int main()
{
    int n;
    cin>>n;
    long long int x;
    for(int j=0;j<n;j++)
    {
        cin>>x;
        map<long long int,int>hash;
        for(long long int i=2;i*i<=x;i++)
            while(x%i==0)
            {
                hash[i]++;
                x/=i;
            }
        if(x>1)
            hash[x]++;
        bool flag=true;
        if(hash.size()==1&&hash.begin()->second>=2)
            cout<<"yes"<<endl;
        else
        {
            vector<long long int>bucket(65,0);
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
                cout<<"no"<<endl;
            else if(count<=2&&flag)
                cout<<"yes"<<endl;
        }
    }
    return 0;
}