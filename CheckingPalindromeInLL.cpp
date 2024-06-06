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
Node *Middle(Node *&head){
    Node *slow=head;
    Node *fast=head;
    while(fast!=NULL){
        fast=fast->next;
        if(fast!=NULL) fast=fast->next;
        else break;
        slow=slow->next;
    }
    return slow;
}
void fix(Node *&head){
    Node *mid=Middle(head);
    Node *prev=NULL;
    Node*curr=mid->next;
    mid->next=NULL;
    Node *next=curr;
    while(curr!=NULL){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    mid->next=prev;

}
bool palindrome(Node *&head){
    Node *mid=Middle(head);
    Node *prev=NULL;
    Node*curr=mid->next;
    mid->next=NULL;
    Node *next=curr;
    while(curr!=NULL){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    mid->next=prev;
    Node *temp=head;
    while(prev!=NULL and temp!=mid){
        if(prev->data!=temp->data) {
            fix(head);
            return 0;
        }
        prev=prev->next;
        temp=temp->next;
    }
    if(prev!=NULL) 
    if(prev->data!=temp->data) {
        fix(head);
        return 0;
    }
    fix(head);
    return 1;
}
int main(){
    int n;
    cout<<"Enter length of linked list: ";
    cin>>n;
    cout<<"Enter elements of linked list: ";
    int a;
    cin>>a;
    Node *linked1=new Node(a);
    Node *head=linked1;
    Node *tail=linked1;
    for(int i=1;i<n;i++){
        cin>>a;
        insertAtTail(head,tail,a);
    }
    cout<<palindrome(head)<<endl;
    print(head);
}