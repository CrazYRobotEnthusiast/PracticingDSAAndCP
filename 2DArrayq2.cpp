#include<iostream>
#include<vector>
using namespace std;
int main(){
    cout<<"Enter dimensions of matrix:";
    int r1,c1;
    cin>>r1>>c1;
    int a[r1][c1];
    cout<<endl;
    cout<<"Enter matrix:-";
    for(int i=0;i<r1;i++){
        for(int j=0;j<c1;j++){
            cin>>a[i][j];
        }
    }
    int transpose[c1][r1];
    for(int i=0;i<r1;i++){
        for(int j=0;j<c1;j++){
            transpose[j][i]=a[i][j];
        }
    }
    cout<<"Transpose of given matrix:-"<<endl;
    for(int i=0;i<c1;i++){
      for(int j=0;j<r1;j++){
        cout<<transpose[i][j]<<" ";
        
    }
    cout<<endl;
    }
}