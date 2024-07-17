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
pair<int,int>maxSum(Node*&root){
    if(root==NULL) return {0,0};
    
    pair<int,int>leftC=maxSum(root->left);
    pair<int,int>rightC=maxSum(root->right);
    
    return{max(leftC.first,leftC.second)+max(rightC.first,rightC.second),leftC.first+rightC.first+root->data};
    
}
int getMaxSum(Node *root) 
{
    pair<int,int> p=maxSum(root);
    return max(p.first,p.second);
}
int main(){

}