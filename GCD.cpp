#include<iostream>
using namespace std;
int f(int a,int b){
    if (a>b) swap(a,b);
    return (b%a==0)?a:f(a,b%a);
}
int main(){
    cout<<f(72,15);
}