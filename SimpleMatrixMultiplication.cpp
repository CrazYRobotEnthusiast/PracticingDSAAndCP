#include<iostream>
#include<vector>
using namespace std;
int main(){
    cout<<"Enter dimensions of first matrix:";
    int r1,r2,c1,c2;
    cin>>r1>>c1;
    int a[r1][c1];
    cout<<endl;
    cout<<"Enter first matrix:-";
    for(int i=0;i<r1;i++){
        for(int j=0;j<c1;j++){
            cin>>a[i][j];
        }
    }
    cout<<"Enter dimensions of second matrix:";
    cin>>r2>>c2;
    if(c1!=r2){
        cout<<"THE TWO MATRICES CANNOT BE MULTIPLIED...WTF ARE YOU DOING? GO GET A LIFE!!!";
    }
    int b[r1][c1];
    cout<<endl;
    cout<<"Enter second matrix:-";
    for(int i=0;i<r2;i++){
        for(int j=0;j<c2;j++){
            cin>>b[i][j];
        }
    }
    int c[r1][c2];
    for(int i=0;i<r1;i++){
        for(int j=0;j<c2;j++){
            c[i][j]=0;
            for(int n=0;n<c1;n++){
                c[i][j]+=a[i][n]*b[n][j];
            
            }
        }
    }
    cout<<"Printing the product of the matrices:-"<<endl;
    for(int i=0;i<r1;i++){
        for(int j=0;j<c2;j++){
            cout<<c[i][j]<<" ";
        }
        cout<<endl;
    }


}