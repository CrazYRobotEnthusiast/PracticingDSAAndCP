#include<iostream>
using namespace std;
int main(){
    int r;
    cout<<"Enter no. of rows: ";
    cin>>r;
    for(int i=1;i<=r;i++){
        for(int j=1;j<=2*r-1;j++){
            if((j>=(r+1-i))&&(j<=(r+i-1))){
                cout<<"*";
            }
            else{
                cout<<" ";
            }
        }
        cout<<endl;
    }
}