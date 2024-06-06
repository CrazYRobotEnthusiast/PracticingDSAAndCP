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
bool detectLoop(Node *head){
    if(head==NULL) return 0;
    Node *fast=head;
    Node *slow=head;
    while(slow!=NULL and fast!=NULL){
        fast=fast->next;
        if(fast!=NULL) fast=fast->next;
        slow=slow->next;
        if(slow==fast) return 1;
    }
    return 0;
}
Node *startOfLoop(Node *head){
    if(detectLoop(head)){
        Node *fast=head;
        Node *slow=head;
        do{
            fast=fast->next->next;
            slow=slow->next;
        }while(fast!=slow);

        slow=head;

        while(fast!=slow){
            fast=fast->next;
            slow=slow->next;
        }
        cout<<"Start of loop is node with data: "<<fast->data;
        return fast;

    }
    else{
        cout<<"No Loop is present";
        return NULL;
    }

}
int main(){
    Node *a=new Node(1);
    Node *head=a;
    Node *tail=a;
    insertAtTail(head,tail,2);
    insertAtTail(head,tail,4);
    insertAtTail(head,tail,8);
    insertAtTail(head,tail,16);
    tail->next=head->next->next;
    Node *LoopKaStart=startOfLoop(head);
}