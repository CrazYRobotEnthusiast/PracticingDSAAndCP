#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
    Node(int d){
        this->data=d;
        this->next=this;
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
void insertingNode(Node *&tail,int element,int d){ //This function will create and store a node containing data d after the node containing data element
    if(tail==NULL){
        Node *newNode=new Node(d);
        tail=newNode;
    }
    else{
        Node *temp=tail;
        while(temp->data!=element){
            temp=temp->next;
        }
        Node *nodeToInsert=new Node(d);
        nodeToInsert->next=temp->next;
        temp->next=nodeToInsert;
    }
}
void print(Node *&tail){
    Node *temp=tail;
    do{
        cout<<temp->data<<" ";
        temp=temp->next;
    }while(temp!=tail);
    cout<<endl;
    return;
}
void deletingValue(Node *&tail,int d){
    if(tail==NULL){
        cout<<"List is empty, please check again"<<endl;
        return;
    }
    Node *temp=tail;
    while(temp->next->data!=d){
        temp=temp->next;
    }
    Node *nodeToDelete=temp->next;
    if(tail==nodeToDelete) tail=temp;
    temp->next=nodeToDelete->next;
    nodeToDelete->next=NULL;
    delete nodeToDelete;
    

}
int main(){

}