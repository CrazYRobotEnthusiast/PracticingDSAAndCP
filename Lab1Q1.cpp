#include<iostream>
using namespace std;
int GCD(int a,int b){
   if(a>b){
    int temp=a;
    a=b;
    b=temp;
   }
   if(b%a==0) return a;
   else return GCD(a,b%a);
}
int main(){
    int a,b;
    cout<<"Enter first integer: ";
    cin>>a;
    while(a<0){
    cout<<"Please input positive number:";
    cin>>a;
    }
    cout<<"Enter second integer: ";
    cin>>b;
    while(b<0){
    cout<<"Please input positive number:";
    cin>>b;
    }
    cout<<GCD(a,b);
    
}