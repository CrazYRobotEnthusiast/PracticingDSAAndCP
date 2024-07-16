#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    bool ans[t];
    for(int k=0;k<t;k++){
        int n;
        cin>>n;
        if(n==1){
            int a;
            cin>>a;
            ans[k]=a;
        }
        else{
            char arr[n];
            for(int i=0;i<n;i++) cin>>arr[i];
            int c1=0;
            int c0=0;
            int j=0;
            while(j<n){
                if(arr[j]=='0'){
                    c0++;
                    while(j<n and arr[j]=='0') j++;
                }
                else if(arr[j]=='1'){
                    c1++;
                    j++;
                }
            }
            
            if(c1>c0) ans[k]=1;
            else ans[k]=0;
            
            
        }
    }
    for(int i=0;i<t;i++){
        if(ans[i]) cout<<"yes"<<endl;
        else cout<<"no"<<endl;
    }
}