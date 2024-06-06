#include<iostream>
using namespace std;
bool f(int n,int *temp){
    if (n<10){
        bool c=(*temp%10==n%10)?1:0;
        *temp/=10;
        return c;
    }
    bool a=f(n/10,temp);
    bool c=(*temp%10==n%10)?1:0;
    *temp/=10;
    return a and c;
}
int main(){
    int a=12621;
    int x=a;
    int *b=&x;
    cout<<f(a,b);
}
