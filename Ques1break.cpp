//Print the first multiple of 5 which is also divisible by 7.
#include<iostream>
using namespace std;
int main(){
    int i=1;
    while(true){
        if((i*5)%7==0){
            cout<<i*5;
            break;
        }
        i++;
    }
}