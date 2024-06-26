#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    int ans[t];
    for(int k=0;k<t;k++){
        int n,l,r;
        cin>>n>>l>>r;
        int arr[n];
        for(int i=0;i<n;i++) cin>>arr[i];
        deque<int> q;
        int currSum=0;
        int rounds=0;
        for(int i=0;i<n;i++){
            if(q.empty() or currSum+arr[i]<=r) {
                q.push_back(arr[i]);
                currSum+=arr[i];
            }
            else{
                while(!q.empty() and currSum+arr[i]>r) {
                    currSum-=q.front();
                    q.pop_front();
                }
                q.push_back(arr[i]);
                currSum+=arr[i];
            }
            if(currSum>=l and currSum<=r){
                rounds++;
                currSum=0;
                while(!q.empty()) q.pop_front();
            }
        }
        ans[k]=rounds;
    }
    for(int i=0;i<t;i++) cout<<ans[i]<<endl;
}