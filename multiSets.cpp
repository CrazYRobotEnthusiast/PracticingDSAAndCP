#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    int ans[t];
    for(int i=0;i<t;i++){
        int n,k;
        cin>>n>>k;
        if(n==1) ans[i]=0;
        else if(k==2) ans[i]=n-1;
        else{
            ans[i]=n/(k-1);
            if(n%(k-1)>1) ans[i]++;
        
        }
    }
    for(int i=0;i<t;i++) cout<<ans[i]<<endl;
}