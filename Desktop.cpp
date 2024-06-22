#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    int ans[t];
    for(int k=0;k<t;k++){
        int x;
        int y;
        cin>>x>>y;
        int screens=0;
        int extraSpace=0;
        if(y%2!=0){
            y--;
            screens++;
            extraSpace+=11;
        }
        int temp=y/2;
        extraSpace+=temp*7;
        screens+=temp;
        
        x-=extraSpace;
        if(x<=0) ans[k]=screens;
        else {
            if(x%15!=0){
                screens++;
                x=x-x%15;
            }
            screens+=x/15;
        }
        ans[k]=screens;
        }
    
    for(int i=0;i<t;i++){
        cout<<ans[i]<<endl;
    }
}