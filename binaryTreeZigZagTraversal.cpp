#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node *left, *right;
    Node(int d){
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }
};
void zigzag(Node *&root){
    if(root==NULL) return;
    queue<Node*> q;
    stack<Node*>s;
    q.push(root);
    q.push(NULL);
    int h=1;
    while(!q.empty()){
        if(q.front()==NULL){
            q.pop();
            h++;
            if(!s.empty()){
                while(!s.empty()){
                    q.push(s.top());
                    s.pop();
                }
                q.push(NULL);
            }
        }
        else{
        Node*temp=q.front();
        cout<<temp->data;
        q.pop();
        if(h%2==1){
            if(temp->left)s.push(temp->left);
            if(temp->right)s.push(temp->right);
        }
        else{
            if(temp->right)s.push(temp->right);
            if(temp->left)s.push(temp->left);
        }
        }
    }
}
void buildTree(Node *&root){
    int d;
    cout<<"Enter data: ";
    cin>>d;
    if(d==-1) return;
    root=new Node(d);
    cout<<"Enter data for node left of "<<d<<":"<<endl;
    buildTree(root->left);
    cout<<"Enter data for node right of "<<d<<":"<<endl;
    buildTree(root->right);
    return;
}
int main(){
    Node *root;
    buildTree(root);
    zigzag(root);
}