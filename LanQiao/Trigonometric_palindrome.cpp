#include<iostream>
using namespace std;
bool palindrome(int num)
{
    int ans=0;
    int t=num;
    while(t)
    {
        ans=ans*10+t%10;
        t/=10;
    }
    return ans==num;
}
int main()
{
    int i=4497;
    for(;;i++)
    {
        int dig=i%10;
        if(dig==0||dig==4||dig==5)
            continue;
        if(palindrome(i*(i+1)/2))
            break;
    }
    cout<< i*(i+1)/2;
    return 0;
}
