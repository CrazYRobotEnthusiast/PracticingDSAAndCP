#include<iostream>
using namespace std;
int main(){
    int r;
    cout<<"Enter no. of rows: ";
    cin>>r;
    for(int i=1;i<=r;i++){
        for (int j=1;j<= r+i-1;j++){
            if(j<=r-i){
                cout<<" ";
            }
            else if((j>r-i)&&(j<=r)){
                cout<<j-r+i;
            }
            else{
                cout<<i+r-j;
            }
        }
        cout<<endl;
    }
}