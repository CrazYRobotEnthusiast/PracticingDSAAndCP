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
void bfs(int i,Graph g,int visited[],Node *&head){
    if(i==-1) return;
    for(int j=0;j<g.AdjLists[i].size();j++){
        if(visited[g.AdjLists[i][j]]==0){
            cout<<g.AdjLists[i][j]<<" ";
            visited[g.AdjLists[i][j]]=1;
            queue(head,g.AdjLists[i][j]);
        }
    }
    int a=dequeue(head);
    bfs(a,g,visited,head);


}
void BFS(Graph g){
    int visited[g.V];
    for(int i=0;i<g.V;i++)visited[i]=0;
    Node *head=NULL;
    for(int i=0;i<g.V;i++){
        if(visited[i]==0){
         cout<<i<<" ";
         visited[i]=1;
         bfs(i,g,visited,head);
        }
    }
}
int main(){
    Graph g(5);
    g.addEdge(0,3,false);
    g.addEdge(1,3,false);
    g.addEdge(1,4,false);
    g.addEdge(1,2,false);
    g.printAdjLists();
    BFS(g);
}