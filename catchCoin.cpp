#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    bool ans[t];
    for(int k=0;k<t;k++){
        int x,y;
        cin>>x>>y;
        if(y>=-1){
            ans[k]=true;
        }
        else ans[k]=false;
    }
    for(int i=0;i<t;i++){
        if(ans[i]) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}