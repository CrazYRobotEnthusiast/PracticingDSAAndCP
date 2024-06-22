#include<bits/stdc++.h>
using namespace std;
int main(){

    int t;
    cin>>t;
    bool ans[t];

    for(int j=0;j<t;j++){
        int n;
        cin>>n;
        string a,b,c;
        cin>>a>>b>>c;
        bool temp=false;
        for(int i=0;i<n;i++){
            if(a[i]==b[i] and a[i]!=c[i]){
                temp=true;
                break;
            }
            if(a[i]!=b[i] and b[i]!=c[i] and a[i]!=c[i]){
                temp=true;
                break;
            }
        }
       
        ans[j]=temp;
    }
    for(int i=0;i<t;i++){
        if(ans[i]) cout<<"YES";
        else cout<<"NO";
        cout<<endl;
    }
}