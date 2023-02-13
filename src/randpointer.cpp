#include<iostream>
#include<vector>
#include<random>
#include<algorithm>
#include<map>
using namespace std;
class Node//双端链表结点
{
public:
    int data;
    Node*next;
    Node*pre;
    Node*rand;
    Node(int Data,Node*p=nullptr)
    {
        data=Data;
        next=nullptr;
        rand=nullptr;
        pre=nullptr;
    }
};
class List
{
public:
    int cur;
    Node*head;
    Node*tail;

    List(Node*p=nullptr)
    {
        cur=0;
        head=p;
        tail= nullptr;
    }
    List(const vector<int>&v)
    {
        if(!v.empty())
        {
            cur=(int)v.size();
            head=new Node(v[0]);
            tail=head;
            for(int i=1;i<v.size();i++)
            {
                Node*p=tail;
                tail->next=new Node(v[i]);
                tail=tail->next;
                tail->pre=p;
            }
        }
    }
    void push_back(int value)
    {
        cur++;
        if(head==nullptr)
        {
            head=new Node(value);
            tail=head;
        }
        else
        {
            Node*p=tail;
            tail->next=new Node(value);
            tail=tail->next;
            tail->pre=p;
        }
    }
    void insert(Node*&p,int value)
    {
        Node*s=new Node(value);
        Node*r=p->next;
        s->pre=p;
        s->next=r;
        p->next=s;
        if(r)
            r->pre=s;
        cur++;
    }
    void rand_pointer()const
    {
        random_device rd;  //如果可用的话，从一个随机数发生器上获得一个真正的随机数
        mt19937 gen(rd()); //gen是一个使用rd()作种子初始化的标准梅森旋转算法的随机数发生器
        uniform_int_distribution<> distrib(0, cur-1);
       vector<int>v(cur);
       for(auto &i:v)
           i=distrib(gen);
        for_each(v.begin(),v.end(),[](int value){cout<<value<<",";});
        cout<<endl;
       Node*p=head;
       for(int i=0;i<cur;i++)
       {
           Node*q=p;
           if(v[i]>=i)//往右走
           {
               for(int j=0;j<v[i]-i;j++)
                   q=q->next;
               p->rand=q;
           }
           else//往前走
           {
               for (int j = 0; j < i - v[i]; j++)
                   q = q->pre;
               p->rand = q;
           }
           p=p->next;
       }
        
    }
    List&copy()
    {
        pair<Node*,int>hashmap[cur];
        Node*p=head;
        for(int i=0;p!= nullptr;i++)
        {
            hashmap[i].first=p;
            p=p->next;
        }
        p=head;
        for(int i=0;p!= nullptr;i++)
        {
            for(int k=0;k<cur;k++)
                if(p->rand==hashmap[k].first)
                {
                    hashmap[i].second=k;
                    break;
                }
            p=p->next;
        }
        List *new_head=new List;
        for(int i=0;i<cur;i++)
            new_head->push_back(hashmap[i].first->data);
        p=new_head->head;
        for(int i=0;i<cur;i++)
        {
            if(hashmap[i].second>=i)//往右走
            {
                Node*q=p;
                for(int j=0;j<hashmap[i].second-i;j++)
                    q=q->next;
                p->rand=q;
            }
            else//往前走
            {
                Node *q = p;
                for (int j = 0; j < i - hashmap[i].second; j++)
                    q = q->pre;
                p->rand = q;
            }
            p=p->next;
        }
        return *new_head;
    }
    List &copy_1()
    {
        map<Node*,Node*>hashmap;
        Node*p=head;
        for(int i=0;p;i++, p=p->next)
            hashmap.insert(make_pair(p,new Node(p->data)));
        p=head;
        List *l=new List();
        while(p)
        {
            if(p->next)
                hashmap.find(p)->second->next=hashmap.find(p->next)->second;
            if(p->pre)  
                hashmap.find(p)->second->pre=hashmap.find(p->pre)->second;
            hashmap.find(p)->second->rand=hashmap.find(p->rand)->second;
            p=p->next;
        }
        l->head=hashmap.find(head)->second;
        return *l;
    }
    List &copy_3()
    {
        Node*p=head;
        Node*front=nullptr;
        while(p)
        {
            front=p;
            p=p->next;
            insert(front,front->data);
        }
        p=head;
        Node*new_p=p->next;
        Node*new_head=head->next;
        while(new_p->next)
        {
            new_p->rand = p->rand->next;
            p = new_p->next;
            new_p=p->next;
        }
        p=head;
        new_p=p->next;
        while(true)
        {
            cur--;
            p->next = new_p->next;
            if (new_p->next)
                new_p->next->pre = p;

            p = new_p->next;
            if(!p)
            {
                new_p->next=nullptr;
                break;
            }
            if(p->next)
                p->next->pre=new_p;
            new_p=p->next;
        }
        List*l=new List();
        l->head=new_head;
        return *l;
    }
    void Print(bool flag=true)
    {
        if(flag)
        {
            Node*p=head;
            while(p)
            {
                cout<<p->data<<",";
                p=p->next;
            }
        }
        else
        {
            Node*p=tail;
            while(p)
            {
                cout<<p->data<<",";
                p=p->pre;
            }
        }
        cout<<endl;
    }
    void randPrint()
    {
        Node*p=head;
        while(p)
        {
            cout<<p->rand->data<<",";
            p=p->next;
        }
        cout<<endl;
    }
    
};
int main()
{
    vector<int>vl{9,7,1,6,9,1,4,6,9,7,2};
    List l(vl);
    l.rand_pointer();
    List r=l.copy();
    List t=l.copy_1();
    List s=l.copy_3();
    l.Print();
    t.Print();
    s.Print();
    r.Print();
    l.randPrint();
    r.randPrint();
    t.randPrint();
    s.randPrint();
    l.Print();
    int b=10;
    auto foo=[b](int a){return a+b;};
    cout<<foo(b)<<endl;
    return 0;
}