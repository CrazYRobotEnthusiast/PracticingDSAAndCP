#include<iostream>
using namespace std;
int add(int,int);
int main(){
    int b=add(1,3);
    cout<<b;
}

int add(int num1,int num2){
    return num1+num2;
}