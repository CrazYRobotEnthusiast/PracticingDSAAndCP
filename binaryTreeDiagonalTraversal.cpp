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
void trying(Node*&root,int a,map<int,vector<int>> &m){
    if(root==NULL) return;
    trying(root->left,a+1,m);
    m[a].push_back(root->data);
    trying(root->right,a,m);
    return;
}
vector<int> diagonal(Node *root)
{
   map<int,vector<int>> m; //diagonal index,Node data;
   queue<pair<int,Node*>>q;
   q.push({0,root});
   vector<int> ans;
   if(root==NULL) return ans;
   trying(root,0,m);
   for(auto it:m){
       for(auto i:it.second){
        ans.push_back(i);       
   }
}
return ans;
}