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
    bool find(int value)
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
    Node* middle()
    {
        Node*p=head,*q=head;
        if(head==nullptr)
            return nullptr;
        while(q->next&&q->next->next)
        {
            p=p->next;
            q=q->next->next;
        }
        return p;
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
    bool reverse()
    {
        if(head==nullptr)
            return false;
        Node*p=head,*r,*q;
        r = nullptr;
        q = nullptr;
        while(p)
        {
            r=q;
            q=p;
            p=p->next;
            q->next=r;
        }
        head=q;
        return true;
    }
    static bool reverse(Node*cur)
    {
        if (cur == nullptr)
            return false;
        Node *p = cur, *r, *q;
        r = nullptr;
        q = nullptr;
        while (p) {
            r = q;
            q = p;
            p = p->next;
            q->next = r;
        }
        cur = q;
        return true;
    }
    bool palindrome()
    {
        Node*cur=middle();//找到中点
        reverse(cur);//反转中点以后的结点
        Node*p=head,*q=rear;
        while(q!=cur&&p->data==q->data)//依次判断结点数据域是否相等
        {
            p=p->next;
            q=q->next;
        }
        reverse(rear);//再反转回来
        if(q==cur)//如果从后往前找到中点都相等，说明是回文
            return true;
        return false;
    }
};
template<class T>
bool palindrome(vector<T>v)
{
    stack<T>s;
    for(int i=0;i<v.size();i++)
        s.push(v[i]);
    for(int i=0;i<v.size();i++)
        if(v[i]==s.top())
            s.pop();
        else
            return false;
    return true;
}
int main() {
    vector<int>v{1,2,3,4,3,2,1};
    cout<<palindrome(v)<<endl;
    List l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.push_back(4);
    l.push_back(4);
    l.push_back(3);
    l.push_back(2);
    l.push_back(1);
    cout<<l.middle()->data<<endl;
    l.Print();
    cout<<"abc"<<l.palindrome()<<endl;
    l.Print();
    return 0;
}
