#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
    Node *random;
    Node(int d){
        this->data=d;
        this->next=NULL;
    }
    ~Node(){
        int value=this->data;
        if(this->next!=NULL){
            delete next;
            this->next=NULL;
        }
        cout<<"Memory is free for node for with data "<<value<<endl;
    }
};
void insertAtTail(Node *&head,Node *&tail,int d){
    if(tail==NULL){
        Node *temp=new Node(d);
        head=temp;
        tail=temp;
    }
    else{
        Node *temp=new Node(d);
        tail->next=temp;
        tail=temp;
    }
}
int getLength(Node *&head){
    Node *temp=head;
    int cnt=0;
    while(temp!=NULL){
        temp=temp->next;
        cnt++;
    }
    return cnt;
}
void print(Node *&head){
    Node *temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
    return;
}
void printR(Node *&h){
    int c=0;
    Node *temp=h;
    while(temp!=NULL and c<=10){
        cout<<temp->data<<" ";
        c++;
        temp=temp->random;
    }
    cout<<endl;
    return;
}
Node *Cloning(Node *&h){
    Node *temp=h;
    Node *ClonedHead=NULL;
    Node *ClonedTail=NULL;
    while(temp!=NULL){
        insertAtTail(ClonedHead,ClonedTail,temp->data);
        temp=temp->next;
    }
    Node *tempC=ClonedHead;
    temp=h;
    Node *next=NULL;
    Node *nextC=NULL;
    while(temp!=NULL){
        next=temp->next;
        nextC=tempC->next;
        temp->next=tempC;
        tempC->next=next;
        temp=next;
        tempC=nextC;
    }
    Node *original=h;
    while(original!=NULL){
        original->next->random=original->random;
        original=original->next->next;
    }
    tempC=ClonedHead;
    temp=h;
    while(temp!=NULL){
        temp->next=temp->next->next;
        tempC->next=tempC->next->next;
        temp=temp->next;
        tempC=tempC->next;
    }
    return ClonedHead;
          
}