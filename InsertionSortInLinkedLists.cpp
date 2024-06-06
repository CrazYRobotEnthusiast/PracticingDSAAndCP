#include<iostream>
using namespace std;
class Node{
    public:
    int d;
    Node *next;
    Node *prev;
    Node(int d){
        this->d=d;
        this->next=NULL;
        this->prev=NULL;
    }
};
void insertInList(Node *&tail,int d){
    if(tail==NULL) tail=new Node(d);
    else{
        Node *temp=new Node(d);
        tail->next=temp;
        temp->prev=tail;
        tail=temp;
    }
    return;
}
Node *returnHead(Node *&tail){
    Node *head=tail;
    while(head->prev!=NULL) head=head->prev;
    return head;
}
void print(Node *& head){
    Node *temp=head;
    while(temp!=NULL){
        cout<<temp->d<<" ";
        temp=temp->next;
    }
    cout<<endl;
    return;
}
void insertionSort(Node *&head){
    Node *temp=head->next;
    while(temp!=NULL){
        int k=temp->d;
        Node *j=temp->prev;
        while(j!=NULL and j->d>k){
            j->next->d=j->d;
            j=j->prev;
        }
        if(j==NULL) head->d=k;
        else j->next->d=k;
        temp=temp->next;
    }
}
int main(){
    int n;
    cout<<"Enter no of elements:";
    cin>>n;
    cout<<"Enter the elements:";
    int d;
    cin>>d;
    Node *sequence=new Node(d);
    for(int i=1;i<n;i++){
        int a;
        cin>>a;
        insertInList(sequence,a);
    }
    Node *head=returnHead(sequence);
    print(head);
    insertionSort(head);
    print(head);
    return 0;
}