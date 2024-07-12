#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    int ans[t];
    for(int k=0;k<t;k++){
        int total,l;
        cin>>total>>l;
        int arr[l];
        for(int i=0;i<l;i++) cin>>arr[i];
        int m=INT_MIN;
        int steps=0;
        for(int i=0;i<l;i++) if(arr[i]>m)m=arr[i];
        if(m==1) steps=l-1;
        else{
            for(int i=0;i<l;i++) steps+=2*arr[i]-1;
            steps-=2*m-1;
        }
        ans[k]=steps;
    }
    for(int i=0;i<t;i++) cout<<ans[i]<<endl;
}