#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    bool ans[t];
    for(int k=0;k<t;k++){
        long long int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        if(x1<y1 and x2<y2) ans[k]=1;
        else if(y1<x1 and y2<x2) ans[k]=1;
        else ans[k]=0;
    }
    for(int i=0;i<t;i++){
        if(ans[i]) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}