#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a=n;
    int digits=0;
    int n7=0;
    int ans=0;
    while(a!=0){
        int curr=a%10;
        a=a/10;
        digits++;
        if(curr==7){
            ans+=pow(2,digits-1);
        }
    }
    
    if(digits!=0) for(int i=1;i<digits;i++) ans+=pow(2,i);
   
    ans++;
    cout<<ans;

}