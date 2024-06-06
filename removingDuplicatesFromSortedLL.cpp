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
void deletingDuplicates(Node *&head){
    if(head==NULL) return;
    Node *temp=head;
    while(temp!=NULL and temp->next!=NULL){
        if(temp->next->data==temp->data){
            Node *toBeDeleted=temp->next;
            temp->next=temp->next->next;
            toBeDeleted->next=NULL;
            delete toBeDeleted;
            print(head);
        }
        else{
            temp=temp->next;
        }
    }
}
int main(){
    Node *head=new Node(1);
    Node *tail=head;
    insertAtTail(tail,2);
    insertAtTail(tail,2);
    insertAtTail(tail,3);
    insertAtTail(tail,3);
    insertAtTail(tail,3);
    insertAtTail(tail,4);
    insertAtTail(tail,4);
    deletingDuplicates(head);
    print(head);
}