#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
    Node *random;
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
Node *Cloning(Node* &h){
    Node *temp=h;
    Node *Cloned=NULL;
    Node *ClonedTail=NULL;
    while(temp!=NULL){
        insertAtTail(Cloned,ClonedTail,temp->data);
        temp=temp->next;
    }
    temp=h;
    int j=0;
    while(temp!=NULL){
        Node *tempR=temp->random;
        Node *dist=h;
        int cnt=0;
        while(dist!=tempR){
            cnt++;
            dist=dist->next;
        }
        Node *ClonedtempR=Cloned;
        int i=0;
        while(i<=cnt){
            ClonedtempR=ClonedtempR->next;
            i++;
        }
        i=0;
        Node *ClonedTemp=Cloned;
        while(i<=j){
            ClonedTemp=ClonedTemp->next;
            i++;

        }
        ClonedTemp->random=ClonedtempR;
        j++;
        temp=temp->next;
    }
    return Cloned;
}
void printR(Node *&h){
    int c=0;
    Node *temp=h;
    while(temp!=NULL and c<=10){
        cout<<temp->data<<" ";
        c++;
        temp=temp->random;
    }
    cout<<endl;
    return;
}
int main(){

}