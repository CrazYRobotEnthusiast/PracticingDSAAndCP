#include<iostream>
using namespace std;
bool f(int a[],int n,int x,int i){
    if (i==n-1) return a[i]==x;
    return a[i]==x or f(a,n,x,i+1);
}
int main(){
    int a[]={1,2,3,4,5,6,7,8};
    cout<<f(a,8,5,0);
}