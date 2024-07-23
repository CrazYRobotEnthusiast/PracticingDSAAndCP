#include<iostream>
#include<stack>
using namespace std;
class Node{
    public:
    int data;
    Node *leftC;
    Node *rightC;
    Node(int d){
        this->data=d;
        this->leftC=NULL;
        this->rightC=NULL;
    }
};
void morrisonPreorder(Node *&root){
    Node *curr=root;
    while(curr!=NULL){
        if(curr->leftC==NULL){
            cout<<curr->data<<" ";
            curr=curr->rightC;
        }
        else{
            Node *pred=curr->leftC;
            while(pred->rightC!=NULL and pred->rightC!=curr)pred=pred->rightC;
            if(pred->rightC==NULL){
                cout<<curr->data<<" ";
                pred->rightC=curr;
                curr=curr->leftC;
            }
            else{
                curr=curr->rightC;
                pred->rightC=NULL;
            }
        }
    }
}
void buildTree(Node *&root){
    cout<<"Enter Data: ";
    int data;
    cin>>data;
    if(data==-1) return;
    else root=new Node(data);
    cout<<"Enter data for left of "<<root->data<<endl;
    buildTree(root->leftC);
    cout<<"Enter data for right of "<<root->data<<endl;
    buildTree(root->rightC);
}
void preOrder(Node *&root){
    if(root==NULL) return;
    cout<<root->data<<" ";
    preOrder(root->leftC);

    preOrder(root->rightC);
}

int  main(){
    Node *root;
    buildTree(root);
    cout<<endl;
    preOrder(root);
    cout<<endl;
    morrisonPreorder(root);
    cout<<endl;
    preOrder(root);
}