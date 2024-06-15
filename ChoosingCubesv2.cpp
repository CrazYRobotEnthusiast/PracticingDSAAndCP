#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    int ans[t];
    bool f=true;
    for(int i=0;i<t;i++){
        int n;
        int f;
        int k;
        cin>>n>>f>>k;
        int dices[n];
        for(int i=0;i<n;i++) cin>>dices[i];
        int specialNumber=dices[f-1];
        if(n==k){
            ans[i]=1;

            continue;
        }

        int freq[101];
        for(int i=0;i<101;i++) freq[i]=0;
        for(int i=0;i<n;i++) freq[dices[i]-1]++;
 
        int j=100;
        while(k>1){
            if(freq[j]==0){
                while(freq[j]==0) j--;
            }
            freq[j]--;
            k--;
        }
        if(freq[j]==0){
                while(freq[j]==0) j--;
            }
        j=j+1;
        if(j==specialNumber and freq[j-1]==1) ans[i]=1;
        else if(j>specialNumber) ans[i]=0;
        else if(j<specialNumber) ans[i]=1;
        else ans[i]=-1;
    }
    for(int i=0;i<t;i++){
        if(ans[i]==0)cout<<"NO"<<endl;
        else if(ans[i]==1)cout<<"YES"<<endl;
        else cout<<"MAYBE"<<endl;
    }
    
}