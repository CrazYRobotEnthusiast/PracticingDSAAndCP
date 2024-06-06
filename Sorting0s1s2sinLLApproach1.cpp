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
    int arr[3]={0,0,0};
    Node *temp=head;
    while(temp!=NULL){
        arr[temp->data]++;
        temp=temp->next;
    }
    int i=0;
    temp=head;
    while(temp!=NULL){
        temp->data=i;
        arr[i]--;
        if(arr[i]==0) i++;
        temp=temp->next;
    }
    return;
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