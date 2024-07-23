#include<iostream>
#include<stack>
using namespace std;
class Node{
    public:
    int data;
    Node *left;
    Node *right;
    Node(int d){
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }
};    
pair<Node*,Node*> flattening(Node *&root){
    if(root==NULL) return{NULL,NULL};
    if(root->left==NULL and root->right==NULL){
        root->left=NULL;
        return {root,root};
    } 
    pair<Node*,Node*> l={root,root};
    pair<Node*,Node*> r={root,root};
    if(root->left) l=flattening(root->left);
    if(root->right) r=flattening(root->right);
    else r={l.second,l.second};
    root->right=l.first;
    l.second->right=r.first;
    root->left=NULL;
    r.second->right=NULL;
    return {root,r.second};
}
void flatten(Node *&root)
{
    flattening(root);
}