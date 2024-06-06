#include<iostream>
using namespace std;
int f(int h[],int n, int i){
    
    if (i==n-2 or i==n-3) return abs(h[n-1]-h[i]);
    return min(f(h,n,i+1)+abs(h[i+1]-h[i]),f(h,n,i+2)+abs(h[i+2]-h[i]));
}
int main(){
    int a[]={15,17,7,8};
    cout<<f(a,4,0);
}