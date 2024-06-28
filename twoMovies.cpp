#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    int ans[t];
    for(int k=0;k<t;k++){
        int n;
        cin>>n;
        int arr1[n];
        int arr2[n];
        for(int i=0;i<n;i++) cin>>arr1[i];
        for(int i=0;i<n;i++) cin>>arr2[i];
        int first=0;
        int second=0;
        int bpos=0;
        int bneg=0;
        
        for(int i=0;i<n;i++){
            if(arr1[i]==1 and arr2[i]==1) bpos++;
            else if(arr1[i]==-1 and arr2[i]==-1) bneg++;
            else if(arr1[i]==1) first++;
            else if(arr2[i]==1) second++;
        }
        
        if(first>second){
            while(bneg!=0 and first>second){
                first--;
                bneg--;
            }
        }
        else if(second>first){
            while(bneg!=0 and second>first){
                second--;
                bneg--;
            }
        }
        if(first>second){
            while(bpos!=0 and first>second){
                second++;
                bpos--;
            }
        }
        else if(second>first){
            while(bpos!=0 and second>first){
                first++;
                bpos--;
            }
        }
        if(first==second){
            int temp=bpos-bneg;
            first+=temp/2;
            second+=temp/2+temp%2;
        }
        ans[k]=first>second?second:first;
    }
    for(int i=0;i<t;i++) cout<<ans[i]<<endl;
}