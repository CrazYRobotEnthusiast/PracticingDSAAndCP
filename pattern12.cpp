#include<iostream>
using namespace std;
int main(){
    int r;
    cout<<"Enter no. of rows: ";
    cin>>r;
    for (int i=1;i<=r;i++){
        for (int j=1;j<=r+i-1;j++){
            if (i<r){
                if (j==(r-i+1)||j==(r+i-1)){
                    cout<<i;
                }
                else{
                    cout<<" ";
                }
            }
            else{
                cout<<i;
            }
        }
        cout<<endl;
    }
}