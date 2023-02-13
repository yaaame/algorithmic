#include<iostream>
#include<vector>
#include<algorithm>
#include <iterator>
using namespace std;
class Node
{
public:
    int data;
    Node*left;
    Node*right;
    Node(int value,Node*Left=nullptr,Node*Right=nullptr)
    {
        data=value;
        left=Left;
        right=Right;
    }
};
class Tree
{
public:
    Node*root;
    Tree()
    {
        root=nullptr;
    }
    void insert(int value)
    {
        if(root==nullptr)
            root=new Node(value);
        else
        {
            Node*p=root;
            bool left_flag=false;
            bool right_flag=false;
            while(p&&!left_flag&&!right_flag)
                if(value>p->data)//往右子树走
                    if(p->right)//右子树还有数据
                        p=p->right;
                    else
                        right_flag=true;
                else if(value<p->data)
                    if(p->left)
                        p=p->left;
                    else
                        left_flag=true;
                else
                    return;
            if(right_flag)
                p->right=new Node(value);
            if(left_flag)
                p->left=new Node(value);
        }
    }
    void recursion_Order(Node*Root,vector<int>&v)
    {
        if(Root)
        {
            v.push_back(Root->data);
            recursion_Order(Root->left,v);
            v.push_back(Root->data);
            recursion_Order(Root->right,v);
            v.push_back(Root->data);
        }
    }
    void preOrder(Node*Root,vector<int>&v)
    {
        if(Root)
        {
            v.push_back(Root->data);
            preOrder(Root->left,v);
            preOrder(Root->right,v);
        }
    }
    void inOrder(Node*Root)
    {
        
        if(Root)
        {
            inOrder(Root->left);
            inOrder(Root->right);
        }
    }
    void postOrder(Node*Root, vector<int>&v)
    {
       
        if(Root)
        {
            postOrder(Root->left,v);
            postOrder(Root->right,v);
            v.push_back(Root->data);
        }
    }
    bool find_value(int value)const
    {
        if(root==nullptr)
            return false;
        else
        {
            Node*p=root;
            while(p)
                if(value>p->data)//往右子树走
                    if(p->right)//右子树还有数据
                        p=p->right;
                    else
                        return false;
                else if(value<p->data)
                    if(p->left)
                        p=p->left;
                    else
                        return false;
                else
                    return true;
        }
    }
    bool find_ancestor(int value)
    {
        if(!find_value(value))
            return false;
        vector<int>pre;
        preOrder(root,pre);
        vector<int>post;
        postOrder(root,post);
        vector<int>ans(post.size());
        pre.erase(find(pre.begin(), pre.end(),value),pre.end());
        post.erase(post.begin(),find(post.begin(),post.end(),value));
        sort(pre.begin(),pre.end());
        sort(post.begin(), post.end());
        vector<int>::iterator itEnd =set_intersection(pre.begin(),pre.end(),
                         post.begin(), post.end(),
                         ans.begin());
        for_each(ans.begin(),itEnd,[](int num){cout<<num<<" ";});
        return true;
    }
};
int main()
{
    Tree t;
    vector<int>v{5,6,4,2,7};
    for(auto i:v)
        t.insert(i);
    vector<int>pre;
    t.preOrder(t.root,pre);
    vector<int>post;
    t.postOrder(t.root,post);
    vector<int>recursion;
    t.recursion_Order(t.root,recursion);
    for_each(pre.begin(),pre.end(),[](int value){cout<<value<<" ";});
    cout<<endl;
   for_each(post.begin(),post.end(),[](int value){cout<<value<<" ";});
    cout<<endl;
    for_each(recursion.begin(),recursion.end(),[](int value){cout<<value<<" ";});
    cout<<endl;
    t.find_ancestor(0);
    cout<<"排序后"<<endl;
    return 0;
}