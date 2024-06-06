#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
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
Node *Merge(Node *&head1,Node *&head2){
    Node *temp=NULL;
    Node *curr=NULL;
    Node *prev=NULL;
    Node *megaHead=NULL;
    if(head1->data<head2->data){
        curr=head1->next;
        prev=head1;
        temp=head2;
    }
    else{
        curr=head2->next;
        prev=head2;
        temp=head1;
    }
    megaHead=prev;
    while(temp!=NULL and curr!=NULL){
        if(prev->data<= temp->data and curr->data>=temp->data){
            Node *temp1=temp->next;
            prev->next=temp;
            temp->next=curr;
            prev=temp;
            temp=temp1;
        }
        else{
            prev=prev->next;
            curr=curr->next;
        
        }}
        if(temp!=NULL){
            prev->next=temp;
        }
    return megaHead;

}
int main(){
    Node *h1=new Node(1);
    Node *t1=h1;
    insertAtTail(h1,t1,3);
    insertAtTail(h1,t1,4);
    insertAtTail(h1,t1,8); 
    insertAtTail(h1,t1,10);
    Node *h2=new Node(2);
    Node *t2=h2;
    insertAtTail(h2,t2,3); 
    insertAtTail(h2,t2,5); 
    insertAtTail(h2,t2,6); 
    insertAtTail(h2,t2,6); 
    insertAtTail(h2,t2,9); 
    insertAtTail(h2,t2,12); 
    insertAtTail(h2,t2,15);
    Node *head=Merge(h1,h2);
    print(head);

}