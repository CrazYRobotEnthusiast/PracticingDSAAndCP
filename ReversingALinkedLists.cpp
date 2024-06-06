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
/*Mera attempt
void reverseLinkedList(Node *&head,Node *&tail){
    int n=getLength(head);
    for (int i=n-1;i>=0;i--){
        Node *temp=head;
        for (int j=1;j<i;j++){
            temp=temp->next;
        }
        cout<<temp->data<<" "<<temp->next->data<<endl;
        temp->next->next=temp;

    }
    swap(head,tail);
    cout<<"bye bye";
    tail->next=NULL;
    return;
}
*/
//Better Approach:-
void reverseLinkedList(Node *&head){
    Node *prev=NULL;
    Node *curr=head;
    while(head!=NULL){
        head=head->next;
        curr->next=prev;
        prev=curr;
        curr=head;
    }
    head=prev;
    return;
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
    print(head);
    reverseLinkedList(head);
    print(head);
}