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
void solve(Node*&root,int in[],int post[],int inStart,int inEnd,int postStart,int postEnd){
    if(inStart>inEnd||postStart>postEnd) {
        root=NULL;
        return;
    }
    root=new Node(post[postEnd]);
    int pos=-1;
    for(int i=inStart;i<=inEnd;i++){
        if(in[i]==post[postEnd]) pos=i;
    }
    
    solve(root->left,in,post,inStart,pos-1,postStart,postEnd-1-inEnd+pos);
    solve(root->right,in,post,pos+1,inEnd,postEnd-inEnd+pos,postEnd-1);
}
Node *buildTree(int n, int in[], int post[]) {
    // Your code here
Node*root=NULL;
solve(root,in,post,0,n-1,0,n-1);
return root;
}