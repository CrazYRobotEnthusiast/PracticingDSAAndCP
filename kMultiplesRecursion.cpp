#include<iostream>
using namespace std;
void f(int n, int k){
     if (k==0) return;
     f(n,k-1);
     cout<<n*k<<" ";
}
int main(){
    f(5,6);
}