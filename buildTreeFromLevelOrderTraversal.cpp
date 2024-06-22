#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* leftC;
    Node *rightC;
    Node(int d){
        this->data=d;
        this->leftC=NULL;
        this->rightC=NULL;
    }
};
void buildTreeFromLevelOrderTraversal(Node *&root){
    queue<Node *>q;
    int data;
    cin>>data;
    root=new Node(data);
    q.push(root);
    while(!q.empty()){
        Node *temp=q.front();
        q.pop();
        int a;
        cin>>a;
        if(a==-1) break;
        temp->leftC=new Node(a);
        q.push(temp->leftC);
        int b;
        cin>>b;
        if(b==-1) break;
        temp->rightC=new Node(b);
        q.push(temp->rightC); 
    }
}
void levelOrderTraversal(Node *&root){
    queue<Node *>q;
    q.push(root);

    while(!q.empty()){

        
            cout<<q.front()->data<<" ";
            if(q.front()->leftC!=NULL) q.push(q.front()->leftC);
            if(q.front()->rightC!=NULL) q.push(q.front()->rightC);
            q.pop();
        
    }
}
int main(){
    Node *root;
    buildTreeFromLevelOrderTraversal(root);
    levelOrderTraversal(root);
}