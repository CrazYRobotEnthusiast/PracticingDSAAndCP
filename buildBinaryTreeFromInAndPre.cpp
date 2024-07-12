/*

lines 27-29 are O(n) and make our code O(n^2).
To optimise them, we can make a map(int,int) mapping each element of Inorder with its index.
Ex: Inorder:[3 1 5 2 7]  map=[{3,0} {1,1} {5,2} {2,3} {7,4}]

*/
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
void solve(Node*&root,int in[],int pre[],int inStart,int inEnd,int preStart,int preEnd){
    if(inStart>inEnd||preStart>preEnd) {
        root=NULL;
        return;
    }
    root=new Node(pre[preStart]);
    int pos=-1;
    for(int i=inStart;i<=inEnd;i++){
        if(in[i]==pre[preStart]) pos=i;
    }
    
    solve(root->left,in,pre,inStart,pos-1,preStart+1,preStart+pos);
    solve(root->right,in,pre,pos+1,inEnd,preStart+pos-inStart+1,preEnd);
}
Node* buildTree(int in[],int pre[], int n)
{
    Node *root=NULL;
    solve(root,in,pre,0,n-1,0,n-1);
    return root;
}