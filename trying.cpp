#include<iostream>
#include<vector>
using namespace std;
class Node{
    public:
    vector<Node *> child;
    int d;
    Node(int d){
        this->d=d;
    }
};
void AskChild(Node *p){
    cout<<"Enter children of "<<p->d<<" :";
    int a;
    cin>>a;
    int count=0;
    while(a!=-1){
        p->child.push_back(new Node(a));
        cin>>a;
        count++;
    }
    Node *r=new Node(-1);
    p->child.push_back(r);
    for(int i=0;i<count;i++){
        AskChild(p->child[i]);
    }
    return;
}
Node *construct(Node *&root,int d){
    if(d==-1) return NULL;
    if(root==NULL) root=new Node(d);
    cout<<"Enter children of "<<d<<" :";
    int a;
    cin>>a;
    int count=0;
    while(a!=-1){
        root->child.push_back(new Node(a));
        cin>>a;
        count++;
    }
    for(int i=0;i<count;i++){
        AskChild(root->child[i]);
        cout<<root->child[i]->d;
        cout<<root->child[i]->d;
    }
    return root;
}
int main(){
    int r;
    cout<<"Enter root of binary tree: ";
    cin>>r;
    Node *root=NULL;
    root=construct(root,r);
}