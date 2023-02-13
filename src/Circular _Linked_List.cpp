#include<iostream>
using namespace  std;
class Node
{
public:
    int data;
    Node*next;
    Node(int Data,Node*p=nullptr)
    {
        data=Data;
        next=p;
    }
};
class List
{
public:
    Node*head;
    List()
    {
        head=nullptr;
    } 
};
int main()
{
    cout<<"fds"<<endl;
    return 0;
}