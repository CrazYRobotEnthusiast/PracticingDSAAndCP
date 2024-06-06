#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int size;
    cout<<"Enter size of array: ";
    cin>>size;
    int a[size];
    cout<<endl;
    for (int i=0;i<=size-1;i++){
        cin>>a[i];
    }
    cout<<"Enter element to be search: ";
    int b;
    cin>>b;
    int ans=-1;
    for (int i=0;i<=size-1;i++){
        if (a[i]==b){
           ans=i;
           break;
        }
    }
    cout<<ans;
}