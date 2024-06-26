#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    int ans[t];
    for(int i=0;i<t;i++){
        long long int x,y,k;
        cin>>x>>y>>k;
        x++;
        k--;
        while(k>0){
            int a=x>y?y-x%y:y-x;
            
            if(k>=a){
                k-=a;
                x+=a;
                while(x%y==0) x=x/y;
            }
            else break;
        }
        while(x%y==0) x=x/y;
        x+=k;
        ans[i]=x;
    }
    for(int i=0;i<t;i++) {
        cout<<ans[i];
        cout<<endl;
    }
    return 0;
}