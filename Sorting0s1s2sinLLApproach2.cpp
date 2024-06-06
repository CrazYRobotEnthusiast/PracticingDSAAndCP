#include<iostream>
using namespace std;
class Node{
    public:
    Node *next;
    int data;
    Node(int d){
        this->data=d;
        this->next=NULL;
    }

    
};
void insertAtTail(Node *&tail,int d){
    Node *temp= new Node(d);
    if(tail !=NULL) tail->next=temp;
    tail=temp;
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
void sorting012(Node *&head){
     Node *zeroHead=new Node(-1);
     Node *zeroTail=zeroHead;
     Node *oneHead=new Node(-1);
     Node *oneTail=oneHead;
     Node *twoHead=new Node(-1);
     Node *twoTail=twoHead;
     Node *curr=head;
     while(curr!=NULL){
        Node *temp=curr->next;
        if(curr->data==0){
            zeroTail->next=curr;
            zeroTail=curr;
            curr->next=NULL;
        }
        else if(curr->data==1){
            oneTail->next=curr;
            oneTail=curr;
            curr->next=NULL;
        }
        else{
            twoTail->next=curr;
            twoTail=curr;
            curr->next=NULL;
        }
        curr=temp;
     }
     head=zeroHead->next;
     zeroTail->next=oneHead->next;
     oneTail->next=twoHead->next;
}
int main(){
    Node *head=new Node(1);
    Node *tail=head;
    insertAtTail(tail,0);
    insertAtTail(tail,1);
    insertAtTail(tail,1);
    insertAtTail(tail,2);
    insertAtTail(tail,2);
    insertAtTail(tail,0);
    insertAtTail(tail,0);
    sorting012(head);
    print(head);
}