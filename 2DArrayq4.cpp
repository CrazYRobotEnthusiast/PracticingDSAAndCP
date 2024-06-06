#include<iostream>
#include<vector>
using namespace std;



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

    //PRE-PROCESSING
    //Making Row-wise prefix sum matrix:-
    for(int i=0;i<r;i++){
        for(int j=1;j<c;j++){
            a[i][j]+=a[i][j-1];
        }
    }
    //Prefixing above matrix columnwise to make a row & column prefix sum matrix:-
    for(int j=0;j<c;j++){
        for(int i=1;i<r;i++){
            a[i][j]+=a[i-1][j-1];
        }
    }
    //Taking points from user:-
    int l1,r1,l2,r2;
    cout<<"Enter coordinates of first point: ";
    cin>>l1>>r1;
    cout<<"Enter coordinates of second point: ";
    cin>>l2>>r2;
    //Finding Sum:-
    int topSum,leftSum,topLeftSum=0;
    if(l1!=0) topSum=a[l1-1][r2];
    if(r1!=0) leftSum=a[l2][r1-1];
    if(l1!=0 and r1!=0) topLeftSum=a[l1-1][r1-1];
    int sum=a[l2][r2]-topSum-leftSum-topLeftSum;
    cout<<sum;

}