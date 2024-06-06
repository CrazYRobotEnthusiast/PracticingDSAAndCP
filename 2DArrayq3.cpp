#include<iostream>
#include<vector>
using namespace std;

int RectangularSum(vector<vector<int>> a , int r1,int c1,int r2,int c2){
    if (r1>r2) swap(r1,r2);
    if (c1>c2) swap(c1,c2);
    int s=0;
    for(int i=r1;i<=r2;i++){
        for(int j=c1;j<=c2;j++){
            s+=a[i][j];
        }
    }
    return s;
}

int main(){
    cout<<"Enter dimensions of matrix:";
    int r,c;
    cin>>r>>c;
    vector<vector<int>> a(r,vector <int>(c));
    cout<<endl;
    cout<<"Enter matrix:-";
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>a[i][j];
        }
    }
    int r1,c1,r2,c2;
    cout<<"Enter coordinates of first point: ";
    cin>>r1>>c1;
    cout<<"Enter coordinates of second point: ";
    cin>>r2>>c2;
    int sum=RectangularSum(a , r1 , c1 , r2, c2);
    cout<<sum;
}