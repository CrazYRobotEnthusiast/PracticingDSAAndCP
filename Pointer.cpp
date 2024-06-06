#include<iostream>
using namespace std;
int main(){
    void *ptr;
    int x=10;
    ptr=&x;
    cout<< *(int *)ptr;
}