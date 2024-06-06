#include<iostream>
using namespace std;
int Jump(int i,int *Cost,int a[]){
    if(i==0) return *Cost;
    if(i==1){
        *Cost+=abs(a[1]-a[0]);
        return *Cost;
    }
    *Cost=(abs(a[i]-a[i-2])<abs(a[i]-a[i-1]))?abs(a[i]-a[i-2]):abs(a[i]-a[i-1]);
    i=(abs(a[i]-a[i-2])<abs(a[i]-a[i-1]))?i-2:i-1;
    return Jump(i,Cost,a);
}
int main(){
    int cost=0;
    int *c=&cost;
    int a[]={10,30,40,20};
    cost=Jump(3,c,a);
    cout<<cost;
}