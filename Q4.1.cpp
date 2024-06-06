#include<iostream>
using namespace std;
int main(){
    cout<<"Enter the dimensions of the two matrices: ";
    int r1,c1,r2,c2;
    cin>>r1>>c1>>r2>>c2;
    if(c1!=r2){
        cout<<"Matrix multiplication not possible";
    }
    else{
        int mat1[r1][c1];
        int mat2[r2][c2];
        cout<<"Enter values of mat 1:-";
        for(int i=0;i<r1;i++){
            for(int j=0;j<c1;j++){
                cin>>mat1[i][j];
            }
        }
        cout<<"Enter values of mat 2:-";
        for(int i=0;i<r2;i++){
            for(int j=0;j<c2;j++){
                cin>>mat2[i][j];
            }
        }
        int ans[r1][c2];
        for(int i=0;i<r1;i++){
            for(int j=0;j<c2;j++){
                int a=0;
                for(int k=0;k<c1;k++){
                    a+= mat1[i][k]*mat2[k][j];
                }
                ans[i][j]=a;
            }
        }
        for(int i=0;i<r1;i++){
            for(int j=0;j<c2;j++){
                cout<<ans[i][j]<<" ";
            }
            cout<<endl;
        }
    }
}