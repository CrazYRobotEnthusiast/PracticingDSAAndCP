#include<iostream>
#include<vector>
using namespace std;
class Graph{
     public:
     vector<vector<int>>adjLists;
     vector<vector<int>>adjMatrix;
     int V;
     Graph(int V){
        this->V=V;
        adjLists.resize(V);
        adjMatrix.resize(V,vector<int>(V,0));
     }
    void addEdge(int src,int dest,bool isDirected=true){
        adjLists[src].push_back(dest);
        adjMatrix[src][dest]=1;
        if(!isDirected){
            adjLists[dest].push_back(src);
            adjMatrix[dest][src]=1;
        }
     }
     void printAdjLists(){
        cout<<"ADJACENT LISTS"<<endl;
        for(int i=0;i<V;i++){
            cout<<i<<"--> ";
            for(int j=0;j<adjLists[i].size();j++) cout<<adjLists[i][j]<<" ";
            cout<<endl;
        }
     }
     void printAdjmatrix(){
        cout<<"ADJACENT MATRIX"<<endl;
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++) cout<<adjMatrix[i][j]<<" ";
            cout<<endl;
        }
     }
    void DegreeUsingAdjLists(){
        int freq1[V];
        int freq2[V];
        for(int i=0;i<V;i++){
            freq1[i]=0;
            freq2[i]=0;
        }
        for(int i=0;i<V;i++){
            freq1[i]=adjLists[i].size();
            for(int j=0;j<adjLists[i].size();j++){
                freq2[adjLists[i][j]]++;
            }
        }
        cout<<"Vertex : Outdegree : Indegree"<<endl;
        for(int i=0;i<V;i++){
            cout<<i<<" : "<<freq1[i]<<" : "<<freq2[i]<<endl;
        }
    }
};
int main(){
    int n;
    cout<<"Enter number of vertices: ";
    cin>>n;
    int a;
    cout<<"Enter 1 if directed else enter 0: ";
    cin>>a;
    Graph g(5);
    g.addEdge(0, 1,false);
    g.addEdge(0, 2,false);
    g.addEdge(1, 3,false);
    g.addEdge(2, 4,false);
    g.printAdjLists();
    g.printAdjmatrix();
    g.DegreeUsingAdjLists();
}