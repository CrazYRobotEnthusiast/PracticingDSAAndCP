#include<iostream>
using namespace std;
int main(){
    int decimal;
    cout<<"Enter binary no: ";
    cin>>decimal;
    int b=0;
    int c;
    int f=1;
    do{
        c=decimal%2;
        b+=c*f;
        f*=10;
        decimal=decimal/2;
    }while(decimal!=0);
    cout<<"Binary Form: "<<b;
}