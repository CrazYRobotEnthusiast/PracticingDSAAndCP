#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    long long int ans[t];
    for(int i=0;i<t;i++) ans[i]=0;
    for(int i=0;i<t;i++){
        long long int n,a,b;
        cin>>n>>a>>b;
        long long int kMax=min(n,b);
        if(b<a){
            ans[i]=a*n;
        }
        else{
            long long int c=b-a;
            c=min(c,kMax);
            
            ans[i]+=((2*b-c+1)*c)/2;
              
            
            if(n-c>0)ans[i]+=a*(n-c);
        }
    }
    for(int i=0;i<t;i++) cout<<ans[i]<<endl;
}