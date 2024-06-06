#include<iostream>
#include<cmath>
using namespace std;
void squares(){
   cout<<pow(1,2)<<" "<<pow(2,2)<<" "<<pow(3,2)<<" "<<pow(4,2)<<" "<<pow(5,2)<<" "<<endl;
}
void area(int r){
    cout<<"Area: "<<3.14*r*r<<endl;
    cout<<"Circumference: "<<2*3.14*r<<endl;
}
void elections(int age){
    if (age<18) cout<<"Person is not eligible to vote.";
    else cout<<"Person is eligible to vote.";
    cout<<endl;
}
void odd(int a,int b){
    if (a>b){
        int c=a;
        a=b;
        b=c;
    }
    if (a%2==0) a+=1;
    for (int i=a;i<=b;i+=2){
         cout<<i<<" ";
    }
    cout<<endl;
}
bool isprime(int a){
    for (int i=2;i*i<a;i++){
        if (a%i==0) return false;
    }
    return true;
}
void prime(int a,int b){
    for (int i=a;i<=b;i++){
        if (isprime(i)) cout<<i<<" ";
    }
    cout<<endl;
}
int main(){
    int p=5;
}

























