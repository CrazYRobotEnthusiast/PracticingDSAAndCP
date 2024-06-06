#include<iostream>
using namespace std;
int main(){
    string x;
    cout<<"Enter string: ";
    getline(cin,x);
    cout<<"Length of the string is: "<<x.length()<<endl;
    string y="";
    for(int i=x.length()-1;i>=0;i--) y+=x[i];
    cout<<y<<endl;
    if(y==x) cout<<"The string is a pallindrome";
    else cout<<"The string is not a pallindrome";
}