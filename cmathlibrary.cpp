#include<iostream>
using namespace std;
int main(){
    int b;
    cout<<"Enter binary no: ";
    cin>>b;
    int decimal=0;
    int c;
    int f=1;
    do{
        c=b%10;
        decimal+=c*f;
        f*=2;
        b=b/10;
    }while(b!=0);
    cout<<"Decimal Form: "<<decimal;
}