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
void reverse(Node *&head){
    Node *prev=NULL;
    Node *curr=head;
    Node*next=curr;
    while(curr!=NULL){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    head=prev;
}
Node *Adding(Node *&h1,Node *&h2){
    reverse(h1);
    reverse(h2);
    Node *temp1=h1;
    Node *temp2=h2;
    int carryOver=0;
    Node *result=NULL;
    Node *resultTail=NULL;
    while(temp1!=NULL or temp2!=NULL or carryOver!=0){
        int x,y,z;
        if(temp1==NULL) x=0;
        else{ 
        x=temp1->data;
        temp1=temp1->next;
        }
        if(temp2==NULL) y=0;
        else{
        y=temp2->data;
        temp2=temp2->next;}
        z=x+y+carryOver;
        insertAtTail(result,resultTail,z%10);
        carryOver=z/10;

    }
    reverse(h1);
    reverse(h2);
    reverse(result);
    return result;
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
    int n2;
    cout<<"Enter length of linked list: ";
    cin>>n2;
    cout<<"Enter elements of linked list: ";
    int a2;
    cin>>a2;
    Node *linked2=new Node(a2);
    Node *head2=linked2;
    Node *tail2=linked2;
    for(int i=1;i<n2;i++){
        cin>>a;
        insertAtTail(head2,tail2,a);
    }
    Node *r=Adding(head,head2);
    print(head);
    print(head2);
    print(r);

}