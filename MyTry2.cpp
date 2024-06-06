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
void reverseInKGroups(Node *&head,int k){
    Node *curr=head;
    Node *prev=NULL;
    Node *next=NULL;
    Node *newTail=NULL;
    Node *oldTail=NULL;
    int n=getLength(head);
    for(int j=0;j<n/k;j++){
        int cnt=0;

        oldTail=newTail;
        newTail=curr;
        while(cnt<k and curr!=NULL){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            cnt++;
        }
        
        if(j==0){
            head=prev;
        }
        else{
            oldTail->next=prev;
            oldTail=newTail;
        }
    }
    oldTail->next=NULL;
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
    int k;
    cout<<"Enter the size of each group";
    cin>>k;
    reverseInKGroups(head,k);
    print(head);
}