#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node *left,*right;
    Node(int d){
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }
};
void buildTree(Node*&root){
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
void verticalTraversal(Node *&root){
    queue<pair<Node*,int>>q;
    map<int,vector<Node*>> m;
    if(root==NULL) return;
    q.push({root,0});
    while(!q.empty()){
        pair<Node*,int> temp=q.front();
        if(temp.first->left) q.push({temp.first->left,temp.second-1});
        if(temp.first->right) q.push({temp.first->right,temp.second+1});
        m[temp.second].push_back(temp.first);
        q.pop();
    }
    for(auto it:m){
        for(int i=0;i<it.second.size();i++) cout<<it.second[i]->data<<" ";
    }
}
int main(){
    Node *root=NULL;
    buildTree(root);
    verticalTraversal(root);
}