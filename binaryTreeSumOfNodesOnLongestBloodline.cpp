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

pair<int,int>trying(Node*&root){ //height,sum
    if(root==NULL) return {0,0};
    pair<int,int> leftTree=trying(root->left);
    pair<int,int> rightTree=trying(root->right);
    if(leftTree.first==rightTree.first){

        
        return {leftTree.first+1,(leftTree.second>rightTree.second?leftTree.second:rightTree.second)+root->data};
        
    }
    else{

        return {(leftTree.first>rightTree.first?leftTree.first:rightTree.first)+1,(leftTree.first>rightTree.first?leftTree.second:rightTree.second)+root->data};
    }
    
}
int sumOfLongRootToLeafPath(Node *root)
{
    return trying(root).second;
    
    
}