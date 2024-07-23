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
void flatten(Node *&root)
{
    Node *curr=root;
    while(curr!=NULL){
        if(curr->left){
            Node *pred=curr->left;
            while(pred->right!=NULL) pred=pred->right;
            pred->right=curr->right;
            curr->right=curr->left;
            curr->left=NULL;
        }
        curr=curr->right;
    }
}