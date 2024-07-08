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
vector<int> verticalOrder(Node *root)
{
queue<pair<Node*,pair<int,int>>>q; //Node,HorizontalDistance,Level
map<int,map<int,vector<int>>> m; //HorizontalDistance : level,Node
vector<int> ans;
if(root==NULL) return ans;
q.push({root,{0,0}});
while(!q.empty()){
    pair<Node*,pair<int,int>> temp=q.front();
    q.pop();
    m[temp.second.first][temp.second.second].push_back(temp.first->data);
    if(temp.first->left) q.push({temp.first->left,{temp.second.first-1,temp.second.second+1}});
    if(temp.first->right) q.push({temp.first->right,{temp.second.first+1,temp.second.second+1}});
}
for(auto it:m){
    for(auto i:it.second){
        for(auto j:i.second) ans.push_back(j);
    }
}
return ans;
}
int main(){

}