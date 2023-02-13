#include <iostream>
#include<stack>
#include<vector>
using namespace std;
class Node
{
public:
    int data;
    Node*next;
    Node(int Data=0, Node*Next=nullptr)
    {
        data=Data;
        next=Next;
    }
};
class List
{
    Node*head;
    Node*rear;
public:
    List()
    {
        head= nullptr;
        rear= nullptr;
    }
    List(const vector<int>&v)
    {
        if(!v.empty())
        {
            head=new Node(v[0]);
            rear=head;
            for(int i=1;i<v.size();i++)
            {
                rear->next=new Node(v[i]);
                rear=rear->next;
            }
        }
    }
    bool push_back(int value)
    {
        if(head==nullptr)
        {
            head=new Node(value);
            rear=head;
        }
        else
        {
            rear->next=new Node(value);
            rear=rear->next;
        }
        return true;
    }
    bool find_less(int value)
    {
        Node*p=head;
        while(p)
        {
            if(p->data<value)
                return true;
            p=p->next;
        }
        return false;
    }
    bool find_more(int value)
    {
        Node*p=head;
        while(p)
        {
            if(p->data>value)
                return true;
            p=p->next;
        }
        return false;
    }
    bool find_equ(int value)
    {
        Node*p=head;
        while(p)
        {
            if(p->data==value)
                return true;
            p=p->next;
        }
        return false;
    }
    bool del(int value)
    {
        Node *p=head, *pre= nullptr;
        if(p->data==value)
        {
            head=p->next;
            delete p;
            return true;
        }
        while(p)
        {
            pre=p;
            p=p->next;
            if(p&&p->data==value)
            {
                pre->next=p->next;
                delete p;
                return true;
            }
        }
        return false;
    }
    bool pop_front()
    {
        if(head== nullptr)
            return false;
        Node*p=head;
        head=head->next;
        delete p;
        return true;
    }
    bool pop_back()
    {
        if(rear== nullptr)
            return false;
        Node*p=head;
        while(p->next!=rear)
            p=p->next;
        delete rear;
        p->next=nullptr;
        rear=p;
        return true;
    }
    void Print()
    {
        Node*p=head;
        while(p)
        {
            cout<<p->data<<",";
            p=p->next;
        }
        cout<<endl;
    }
    void partition(int value)
    {
        Node*smallL=nullptr,*smallR=nullptr;
        Node*equL=nullptr,*equR=nullptr;
        Node*bigL=nullptr,*bigR=nullptr;
        Node*p=head,*after=nullptr;
        while(p)
        {
            after=p->next;
            p->next=nullptr;
            if(p->data<value)
            {
                if(smallL==nullptr)
                {
                    smallL=p;
                    smallR=p;
                }
                else
                {
                    smallR->next=p;
                    smallR=p;
                }
            }
            else if(p->data==value)
            {
                if(equL==nullptr)
                {
                    equL=p;
                    equR=p;
                }
                else
                {
                    equR->next=p;
                    equR=p;
                }
            }
            else if(p->data>value)
            {
                if(bigL==nullptr)
                {
                    bigL=p;
                    bigR=p;
                }
                else
                {
                    bigR->next=p;
                    bigR=p;
                }
            }
            p=after;
        }    
        head=smallL==nullptr?(equL==nullptr?bigL:equL):smallL;
        rear=bigL==nullptr?(equL==nullptr?smallR:equR):bigR;
        if(smallL!=nullptr)
        {
            smallR->next=equL;//是否连等于区域
            equR=equR==nullptr?smallR:equR;//谁去连大于区域
        }
        if(equR!=nullptr)
            equR->next=bigL;
    }
};
static void partition(vector<int>&v,int m)
{
    int L=-1;
    auto R=v.size();
    for(int i=0;i<R;i++)
        if(v[i]<m)
         swap(v[i],v[++L]);
        else if(v[i]>m)
           swap(v[i--],v[--R]);
    //swap(v[R],v[v.size()-1]);
}
int main()
{
    vector<int>v{1,2,3,5,7,9,7,2};
    int m=5;
    List l(v);
    l.Print();
    l.partition(m);
    l.Print();
    partition(v,m);
    for(auto i:v)
        cout<<i<<",";
    cout<<endl;
    return 0;
}