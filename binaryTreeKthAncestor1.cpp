#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node*left,*right;
    Node(int d){
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }
};
void solve(Node*&root,vector<int> &v,int n){
    if(root==NULL) return;

    if(!v.empty() and v[v.size()-1]==n) { 
        
        return;
    }
    
    v.push_back(root->data);
    solve(root->left,v,n);
    solve(root->right,v,n);
    if(!v.empty() and v[v.size()-1]==n) {

        return;
    }
    
    v.pop_back();
    
}
int kthAncestor(Node *root, int k, int node)
{
    vector<int> v;
    
    solve(root,v,node);
    if(v.size()-1>=k) return v[v.size()-1-k];
    
    return -1;
}