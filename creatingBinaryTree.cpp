#include<iostream>
#include<queue>
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
void buildTree(Node*&root){
    cout<<"Enter data: ";
    int data;
    cin>>data;
    if(data==-1) {
        root=NULL;
        return;
    }
    root=new Node(data);
    cout<<"Enter data for left child of Node "<<data<<endl;
    buildTree(root->leftC);
    cout<<"Enter data for right child of Node "<<data<<endl;
    buildTree(root->rightC);
    return;
}
void levelOrderTraversal(Node *&root){
    queue<Node *>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        if(q.front()==NULL){
            if(q.size()>1) q.push(NULL);
            q.pop();
            cout<<endl;

        }
        else{
            cout<<q.front()->data<<" ";
            if(q.front()->leftC!=NULL) q.push(q.front()->leftC);
            if(q.front()->rightC!=NULL) q.push(q.front()->rightC);
            q.pop();
        }
    }
}
int main(){
    Node *root=NULL;
    buildTree(root);
    levelOrderTraversal(root);  
}