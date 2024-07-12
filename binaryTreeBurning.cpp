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
void createMapping(Node*&root,map<Node*,Node*>&m){
    if(root==NULL) return;
    if(root->left) m[root->left]=root;
    if(root->right) m[root->right]=root;
    createMapping(root->left,m);
    createMapping(root->right,m);
    return;
}
Node *findingTarget(Node*&root,int target){
    if(root==NULL) return NULL;
    if(root->data==target) return root;
    Node* l=findingTarget(root->left,target);
    Node* r=findingTarget(root->right,target);
    if(l) return l;
    if(r) return r;
    return NULL;
}
int minTime(Node* root, int target) 
{
    map<Node*,Node*> m;
    m[root]=NULL;
    
    createMapping(root,m);
    
    Node *startingPoint=findingTarget(root,target);
    
    map<Node*,bool> visited;
    queue<Node*> q;
    q.push(startingPoint);
    int time=0;
    while(!q.empty()){
        
        int size=q.size();
        for(int i=0;i<size;i++){
            Node*temp=q.front();
            visited[temp]=1;
            q.pop();
            if(m[temp] and !visited[m[temp]]){
                
                q.push(m[temp]);
            }
            if(temp->left and !visited[temp->left]){
                
                q.push(temp->left);
            }
            if(temp->right and !visited[temp->right]){
                
                q.push(temp->right);
            }
        }
        if(!q.empty()) time++;
    }
    return time;
}
int main(){

}