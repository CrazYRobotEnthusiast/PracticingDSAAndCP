#include<iostream>
using namespace std;
int main(){
    int r;
    int c;
    cout<<"Enter no. of columns: ";
    cin>>c;
    cout<<"Enter no. of rows: ";
    cin>>r;
    for (int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
        cout<<j;
        }
         cout<<endl;
    }
}