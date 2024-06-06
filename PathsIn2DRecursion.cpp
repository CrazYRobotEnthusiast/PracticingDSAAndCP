#include<iostream>
#include<vector>
using namespace std;
void f(int m,int n,int i,int j,int &totalPaths){
    //We are pointing towards ith row and jth column.
    if (i==m-1 and j==n-1){
        totalPaths+=1;
        return;
    }
    else if(i==m-1){
        f(m,n,i,j+1,totalPaths);
        return;
    }
    else if(j==n-1){
        f(m,n,i+1,j,totalPaths);
        return;
    }
    f(m,n,i+1,j,totalPaths);
    f(m,n,i,j+1,totalPaths);
}
int main(){
    int m,n;
    cin>>m>>n;
    int totalPaths=0;
    f(m,n,0,0,totalPaths);
    cout<<endl;
    cout<<totalPaths;
}