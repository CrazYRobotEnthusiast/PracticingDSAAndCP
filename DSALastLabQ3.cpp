#include<iostream>
#include<vector>
using namespace std;
class Node{
    public:
    int d;
    Node *next;
    Node(int d){
        this->d=d;
        this->next=NULL;
    }
};
void queue(Node *&head,int d){
    if(head==NULL){
        head=new Node(d);
        return;
    }
    else{
        Node *temp=head;
        while(temp->next!=NULL) temp=temp->next;
        temp->next=new Node(d);
        return;
    }
}
int dequeue(Node *&head){
    if(head==NULL) return -1;
    else{
        int a=head->d;
        head=head->next;
        return a;
    }
}
class Graph{
    public:
    vector<vector<int>> AdjLists;
    int V;
    Graph(int V){
        this->V=V;
        AdjLists.resize(V);
    }
    void addEdge(int src,int dest, bool isDirected=true){
        AdjLists[src].push_back(dest);
        if(!isDirected) AdjLists[dest].push_back(src);
    }
    void printAdjLists(){
        cout<<"ADJACENT LISTS"<<endl;
        for(int i=0;i<V;i++){
            cout<<i<<"--> ";
            for(int j=0;j<AdjLists[i].size();j++){
                cout<<AdjLists[i][j]<<" ";
            }
            cout<<endl;
        }
    }
};
void dfs(int i,Graph g,int visited[],int arr[],int &k){
    cout<<i<<" ";
    arr[k]=i;
    k++;
    visited[i]=1;
    for(int j=0;j<g.AdjLists[i].size();j++){
        if(visited[g.AdjLists[i][j]]!=1) dfs(g.AdjLists[i][j],g,visited,arr,k);
    }
    return;
}
void DFS(Graph g){
    int visited[g.V];
    for(int i=0;i<g.V;i++) visited[i]=0;
    int l[g.V];
    int k=0;
    for(int i=0;i<g.V;i++){
        if(visited[i]!=1){
            dfs(i,g,visited,l,k);
        }
    }
    //reversing arrows:-
    cout<<endl;
    Graph G(g.V);
    for(int i=0;i<g.V;i++){
        for(int j=0;j<g.AdjLists[i].size();j++){
            G.AdjLists[g.AdjLists[i][j]].push_back(i);
        }
    }
    for(int i=0;i<g.V;i++) cout<<l[i]<<" ";
    for(int i=0;i<g.V;i++) visited[i]=0;
    int l2[g.V];
    k=0;
    for(int i=0;i<g.V;i++){
        if(visited[l[i]]!=1){
            dfs(l[i],G,visited,l2,k);
            cout<<endl;
        }
    }
}
int main(){
    Graph g(8);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,0);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,7);
    g.addEdge(4,5);
    
    g.addEdge(5,6);
    g.addEdge(6,7);
    g.addEdge(6,4);
    g.printAdjLists();
    DFS(g);

}