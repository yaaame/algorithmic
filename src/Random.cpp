#include <random>
#include <iostream>
#include<map>
using namespace  std;
class A
{
public:
    int a;
    A*p;
    A(int v=10)
    {
        a=v;
        p=this;
    }
    void set_value(int c)
    {
        a=c;
    }
};
A test()
{
    A c(20);
    return c; 
}
int main()
{
    auto a=test();
    auto b={12,1,23,56};
    int arr[]={1,56,6,8,9};
    int m;
    auto p=&m;
   
    
    
    
    
    
    
    
    
    
    
    
    
    
    
//    random_device rd;  //如果可用的话，从一个随机数发生器上获得一个真正的随机数
//    mt19937 gen(rd()); //gen是一个使用rd()作种子初始化的标准梅森旋转算法的随机数发生器
//    uniform_int_distribution<> distrib(1, 6);
//    for (int n=0; n<10; ++n)
//        //使用`distrib`将`gen`生成的unsigned int转换到[1, 6]之间的int中
//        cout << distrib(gen) << ' ';
//    map<int,int>hashmap;
//    hashmap.insert(make_pair(4,2));
//    hashmap.insert(make_pair(2,2));
//    hashmap.insert(make_pair(3,2));
//    hashmap.insert(make_pair(7,2));
//    hashmap.insert(make_pair(1,2));
    
    cout << '\n';
    return 1;
}
