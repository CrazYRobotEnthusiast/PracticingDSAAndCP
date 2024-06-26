#include<iostream>
#include<vector>
using namespace std;
int main(){
    int t;
    cin>>t;
    int ans[t];
    
    for(int i=0;i<t;i++){
        int n,m;
        cin>>n>>m;
        int a=n;
        int j=1;
        a=a|n+m;
        while(n-j>0){
            if(j>m) break;
            a=a|(n-j);
            j*=2;
        }
        j=1;
        while(j<=m){
            a=a|(n+j);
            j*=2;
        }
        ans[i]=a;
    }
    for(int i=0;i<t;i++) cout<<ans[i]<<endl;
    
}