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
void inOrder(Node *&root){
    if(root==NULL) return;
    inOrder(root->leftC);
    cout<<root->data<<" ";
    inOrder(root->rightC);
}
void inOrderUsingIteration(Node *&root){
    stack<Node *>s;
    s.push(root);
    cout<<endl;
    while(!s.empty()){
        while(s.top()->leftC!=NULL) s.push(s.top()->leftC);
        while(!s.empty() and s.top()->rightC==NULL){
            cout<<s.top()->data<<" ";
            s.pop();
        }
        if(!s.empty()){
            cout<<s.top()->data<<" ";
            Node *temp=s.top();
            s.pop();
            s.push(temp->rightC);
        }
    }
}
int  main(){
    Node *root;
    buildTree(root);
    cout<<endl;
    inOrder(root);
    inOrderUsingIteration(root);
}