#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
    Node *prev;
    Node(int d){
        this->data=d;
        this->next=NULL;
        this->prev=NULL;
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
void insertAtHead(Node *&head,Node *&tail,int d){
    if(head==NULL){
        Node *temp=new Node(d);
        head=temp;
        tail=temp;
    }
    else{
        Node *temp=new Node(d);
        temp->next=head;
        head->prev=temp;
        head=temp;
    }
}
void insertAtTail(Node *&head,Node *&tail,int d){
    if(tail==NULL){
        Node *temp=new Node(d);
        head=temp;
        tail=temp;
    }
    else{
        Node *temp=new Node(d);
        tail->next=temp;
        temp->prev=tail;
        tail=temp;
    }
}
void insertAtPosition(Node *&head,Node *&tail,int position,int d){
    if(position==1){
        insertAtHead(head,tail,d);
        return;
    }
    else{
        int cnt=1;
        Node *temp=head;
        Node *nodeToInsert=new Node(d);
        while(cnt<position-1){
            temp=temp->next;
            cnt++;
        }
        if (temp->next==NULL){
            insertAtTail(head,tail,d);
            return;
        }
        nodeToInsert->next=temp->next;
        temp->next->prev=nodeToInsert;
        temp->next=nodeToInsert;
        nodeToInsert->prev=temp;
    }
}
void deletePosition(Node *&head,Node *&tail,int position){
    if(position==1){
      Node*temp=head;
      head=head->next;
      temp->next=NULL;
      temp->prev=NULL; //No need for this but phir bhi for security
      delete temp; 
    }
    else{
       Node *temp=head;
       int cnt=1;
       while(cnt<position-1){
        temp=temp->next;
        cnt++;
       }
       Node *nodeToDelete=temp->next;
       temp->next=nodeToDelete->next;
       temp->next->prev=temp;
       nodeToDelete->next=NULL;
       nodeToDelete->prev=NULL;
       delete nodeToDelete;
       if(temp->next==NULL) tail=temp;
    }
}
int getLength(Node *&head){
    int cnt=1;
    Node *temp=head;
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
}
int main(){
    Node *a=new Node(5);
    Node *head=a;
    Node *tail=a;
    insertAtHead(head,tail,32);
    print(head);
    insertAtTail(head,tail,33);
    print(head);
    insertAtPosition(head,tail,2,34);
    print(head);
    deletePosition(head,tail,3);
    print(head);   
}