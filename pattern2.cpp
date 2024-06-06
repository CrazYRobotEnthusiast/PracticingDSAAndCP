#include<iostream>
using namespace std;
int main(){
    int r;
    int c;
    cout<<"Enter no. of columns: ";
    cin>>c;
    cout<<"Enter no. of rows: ";
    cin>>r;
    /* MY WAY:-
    for (int i=1;i<=r;i++){
        if(i==1||i==r){
            for(int j=1;j<=c;j++){
                cout<<"*";
            }
        }
        else{
            cout<<"*";
            for(int j=1;j<=c-2;j++){
                cout<<" ";
            }
            cout<<"*";
        }
        cout<<endl;
    }

    BETTER WAY:-
    */
   for(int i=1;i<=r;i++){
    for(int j=1;j<=c;j++){
        if((i==1||i==r)||(j==1||j==c)){
            cout<<"*";
        }
        else {
            cout<<" ";
        }

    }
    cout<<endl;
   }
}