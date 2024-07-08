#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    int ans[t];
    
    for(int i=0;i<t;i++){
        int n,m;
        cin>>n>>m;
        int a=n;
        int j=0;

        if(m==0){
            ans[i]=n;
            continue;
        }
        if(n>m){
        while(pow(2,j)<=2*m+1){
            
            int b=1<<j;
            a=a|b;
            j++;
        }
        a=n-m|a;
       
        }
        else{
           int rightMost=m!=0?log2(n+m):-1;
           
           while(rightMost>=0){
            int b=1<<rightMost;
            a=a|b;
            rightMost--;
        } 
        }
        
        a=a|n+m;
        ans[i]=a;
    }
    
    for(int i=0;i<t;i++) cout<<ans[i]<<endl;
    
}