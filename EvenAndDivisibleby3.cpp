#include<iostream>
using namespace std;
int main(){
    int a;
    cin>>a;
    if (a%2==0 && a%3==0){
        cout<<"The number is even and divisible by 3";
    }
    else{
        cout<<"The number does not satisfy the required condition";
    }
}