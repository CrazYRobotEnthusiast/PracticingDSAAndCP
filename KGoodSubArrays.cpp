#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    int ans[t];
    for(int i=0;i<t;i++){
        long long int n,k;
        cin>>n>>k;
        long long int currLength=pow(2,k);
        int subArrays=0;
        if(currLength<n){
        k--;
        
        }
        else{
            cout<<'y';
            for(int i=0;i<n;i++){
            int a=__builtin_popcountll(i);
            
            if(a<=k) currLength+=1;
            else{
                subArrays+=((currLength-1)*currLength)/2;
                
                currLength=0;
            }
        }
        }
        subArrays+=((currLength-1)*currLength)/2;
        ans[i]=subArrays;
    }
    for(int i=0;i<t;i++) cout<<ans[i]<<endl;
}
