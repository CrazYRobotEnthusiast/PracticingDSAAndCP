#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    bool ans[t];
    for(int i=0;i<t;i++){
        int n,m,k;
        cin>>n>>m>>k;
        char arr[n];
        for(int i=0;i<n;i++) cin>>arr[i];
        int j=-1;

        while(j<n){
            bool trial=false;
            if(j+m>=n){
                j=j+m;
                break;
            }
            for(int i=j+m;i>j;i--){
                if(arr[i]=='L' and (j==-1 or arr[j]=='L')){
                    trial=true;
                    j=i;
                    break;
                }
            }
            if(!trial){
                for(int i=j+m;i>j;i--){
                    if(arr[i]=='W'){
                        int temp=i;
                        while(temp!=n and arr[temp]!='L'){
                            if(arr[temp]=='C') break;
                            temp++;
                            k--;
                        }
                        if( (temp==n or arr[temp]=='L') and k>=0){
                            trial=true;
                            j=temp;
                        }
                        break;
                    }
            }
            }
            if(!trial) break;
            }
            if(j<n) ans[i]=0;
            else ans[i]=1;
            if(n==0) ans[i]=1;

        
        }
        for(int i=0;i<t;i++){
            if(ans[i]) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }