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

vector<int> topView(Node *root)
{
    map<int,int> m;
    queue<pair<Node*,int>> q;
    vector<int> ans;
    if(root==NULL) return ans;
    q.push({root,0});
    while(!q.empty()){
        pair<Node *,int> temp=q.front();
        q.pop();
        if(m.find(temp.second)==m.end()) m[temp.second]=temp.first->data;
        if(temp.first->left)q.push({temp.first->left,temp.second-1});
        if(temp.first->right)q.push({temp.first->right,temp.second+1});
    }
    for(auto it:m){
        ans.push_back(it.second);
    }
    return ans;
}