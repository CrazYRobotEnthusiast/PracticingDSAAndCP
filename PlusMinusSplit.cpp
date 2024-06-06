#include<iostream>
using namespace std;
int main(){
    int numCases;
    cin>>numCases;
    int arr[numCases];
    for(int alpha=0;alpha<numCases;alpha++){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int a=0,b=0;
    for(int i=0;i<n;i++){
        if(s[i]=='+'){
            a++;
        }
        else{
            b++;
        }
    }
    arr[alpha]=abs(a-b);
    }
    for(int i=0;i<numCases;i++) cout<<arr[i]<<endl;
}