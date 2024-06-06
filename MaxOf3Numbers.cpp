#include<iostream>
using namespace std;
int main(){
    int a;
    int b;
    int c;
    cin>>a>>b>>c;
    if (a>=b && a>=c){
        cout<<"Maximum number:"<<a;
    }
    else if(b>=a && b>=c){
        cout<<"Maximum number:"<<b;
    }
    else{
        cout<<"Maximum number:"<<c;
    }
}