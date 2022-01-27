#include<iostream>
using namespace std;

class Linkedlist;  // forward decltaion

//class Node
class Node
{
    int data;

public:
    Node* next;
    Node(int data)
    {
        this->data=data;
        this->next=NULL;
    }
    int getData()
    {
        return data;
    }
    friend class Linkedlist;

};
// class linkedlist
class Linkedlist
{
    Node *head,*tail;
    public:
    Linkedlist()
    {
     head=tail=NULL;
    }
void swap(Node *a,Node *b)
{
    int c=a->data;
    a->data=b->data;
    b->data=c;

}
    //Function push_front
    void push_front(int data)
    {
        if(head==NULL)
        {
            Node* temp=new Node(data);
            temp->next=NULL;
            head=temp;
            tail=temp;
        }
        else
        {
             Node* temp=new Node(data);
             temp->next=head;
             head=temp;
        }
    }

    //funtion class push_back
    void push_back(int data)
    {
        if(head==NULL)
        {
          Node* temp=new Node(data);
            temp->next=NULL;
           tail=temp;
        }
        else{
           Node* temp=new Node(data);
             tail->next=temp;
             tail=temp;
        } 
        
    }

    // insertAny position
    void insertPosition(int data,int pos)

    {
        if(pos==0)
        {
           push_front(data);
           return; 
        }
         Node* temp=new Node(data);
        Node* t=head;
        for(int jump=0;jump<pos-1;jump++)
        {
            t=t->next;   
        }
        temp->next=t->next;
        t->next=temp;

    }

    bool SearchLinkedlist(int key)
    {
        Node *p=head;
        while(p!=NULL)
        {
            if(p->getData()==key)
            return true;
            
            p=p->next;
        }
        return false;
    }
    int Linkedlist_delete(int pos)
    {
        
        Node* t=head;
        for(int jump=1;jump<pos-1;jump++)
        {
            t=t->next;   
        }
        t->next=t->next->next;
        

        return t->next->getData();
    }
void reverse_LinkedList(Node *head)
{
    Node *current=head;
    Node *prev=NULL;
    Node *next=NULL;
    while(current!=NULL)
    {
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
     head=prev;
}
int lengthOfLinkedlist(Node *head)
{
    int len=0;
    Node *p=head;
    while(p)
    {
        len++;
        p=p->next;
    }
    return len;

}
 void Bubble_sort(Node *head)
 {
     for(int i=0;i<lengthOfLinkedlist(head)-1;i++)

{
    Node *p=head;
     Node *q=p->next;
     while(q)
     {
         if(p->data>q->data)
         {
         swap(p,q);
         }
         p=q;
         q=q->next;
     } 
}    
     
 } 
    // gethead() function
    Node *gethead()
    {
        return head;
    }
    //function function
    void print(Node* p)
    {
        p=head;
        while(p!=NULL)
        {
            cout<<p->getData()<<" ";
            p=p->next;
        }
    }
};
int main()
{
    Linkedlist l1;
    l1.push_front(23);
    l1.push_front(67);
    l1.push_front(90);
    l1.push_front(12);
    l1.push_front(98);
    l1.push_back(23);
    l1.push_back(61);
     l1.push_front(88);
    l1.push_front(1);
    l1.push_front(997);
    l1.push_back(544);
    l1.push_back(611);
  
    l1.insertPosition(1876,4);
    l1.print(l1.gethead());
    if(l1.SearchLinkedlist(1876))
    {
        cout<<"Found"<<endl;
    }
    else
    {
        cout<<"Not found"<<endl;
    }
     l1.Linkedlist_delete(3);
     l1.print(l1.gethead());
   
    cout<<"reversing the linkedlist"<<endl;
    
     l1.Bubble_sort(l1.gethead());
     l1.print(l1.gethead());
   
    return 0;
}
