#include<bits/stdc++.h>
using namespace std;
void assist(int arr[],string a,string b,int prevp2,int k,int prevCost){
    int curr=prevp2;
    int prev=0;
    bool flag=false;
    int p1,p2=b.length();
    bool hi=false;
    
    for(int i=prevp2;i<b.length();i++){
        for(int j=0;j<a.length();j++){
            
            if(a[j]==b[i]){
            
             p1=j+1;
             p2=i+1;
             flag=true;
             hi=true;
             break;
            }
        }
        if(flag) break;
        curr++;
    }
    prevp2=p2;
    
    while(p2!=b.length()){
        flag=false;
        for(int i=p1;i<a.length();i++){
            if(a[i]==b[p2]){
                flag=true;
                p2++;
                p1=i+1;
            }
        }
        if(!flag) break;
    }
    
    if(p2!=b.length()) curr+=b.length()-p2;
    
    if(arr[k]==-1) arr[k]=curr;
    else arr[k]=arr[k]>curr?curr:arr[k];
    if(hi) assist(arr,a,b,prevp2,k,prev);
}
int main(){
    int t;
    cin>>t;
    int ans[t];
    for(int i=0;i<t;i++) ans[i]=-1;
    for(int k=0;k<t;k++){
        string a;
        string b;
        cin>>a;
        cin>>b;
        assist(ans,a,b,0,k,0);
        ans[k]+=a.length();
    }
    for(int i=0;i<t;i++) cout<<ans[i]<<endl;
}