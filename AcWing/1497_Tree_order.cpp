#include<iostream>
#include<stack>
#include<queue>
#include<vector>
using namespace std;
class Node
{
public:
    int data;
    Node*left=nullptr;
    Node*right=nullptr;
    Node(int Data)
    {
        data=Data;
    }
};
class Tree
{
public:
    Node*root=nullptr;
    void lever_creat(vector<int>&v,int now_index,Node*&Root)//层序创建二叉树
    {
        if(Root==nullptr)
            Root=new Node(v[now_index]);
        if(2*now_index+1<v.size())
        {
            Root->left=new Node(v[2*now_index+1]);
            lever_creat(v,2*now_index+1,Root->left);
        }
        if(2*now_index+2<v.size())
        {
            Root->right=new Node(v[2*now_index+2]);
            lever_creat(v,2*now_index+2,Root->right);
        }
    }
    void pre_order(Node*Root,vector<int>&v)
    {
        if(Root)
        {
            v.push_back(Root->data);
            pre_order(Root->left,v);
           // v.push_back(Root->data);
            pre_order(Root->right,v);
           // v.push_back(Root->data);
            
        }
        else
            v.push_back(INT_MAX);
    }
    void pre_creat(Node*&Root,vector<int>&v)
    {
        static int i=-1;
        i++;
        if(i>=v.size()||v[i]==INT_MAX)
            return ;
        Root=new Node(v[i]);
        pre_creat(Root->left,v);
        pre_creat(Root->right,v);
    }
};
int main()
{
    int n;//结点个数
   // cin>>n;
    vector<int>v{1,2,3,4,5,6};
    Tree t;
    t.lever_creat(v,0,t.root);
    vector<int>pre_v;
    t.pre_order(t.root,pre_v);
    for(auto i:pre_v)
        cout<<i<<" ";
    cout<<endl;
    cout<<"----------------------"<<endl;
    Tree t1;
    t1.pre_creat(t1.root,pre_v); 
    vector<int>pre_v1;
    t.pre_order(t1.root,pre_v1);
    for(auto i:pre_v1)
        cout<<i<<" ";
    cout<<endl;
    return 0;
}