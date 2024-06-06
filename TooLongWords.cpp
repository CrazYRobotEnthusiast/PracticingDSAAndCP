#include<iostream>
using namespace std;
int main(){
    int numCases;
    cin>>numCases;
    string arr[numCases];
    for(int alpha=0;alpha<numCases;alpha++){
       cin>>arr[alpha];
    }
    for(int j=0;j<numCases;j++){

        int n=arr[j].length();
        if(n>10) cout<<arr[j][0]<<n-2<<arr[j][n-1]<<endl;
        else cout<<arr[j]<<endl;
    }
}