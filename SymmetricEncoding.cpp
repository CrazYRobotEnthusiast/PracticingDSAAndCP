#include<bits/stdc++.h>
using namespace std;
void countSort(int arr[],int n,int pos){
    int freq[10];
    for(int i=0;i<10;i++) freq[i]=0;
    for(int i=0;i<n;i++){
        freq[(arr[i]/pos)%10]++;
    }
    for(int i=1;i<10;i++) freq[i]+=freq[i-1];
    int ans[n];
    for(int i=n-1;i>=0;i--){
        ans[--freq[(arr[i]/pos)%10]]=arr[i];
    }
    for(int i=0;i<n;i++) arr[i]=ans[i];
}
void radixSort(int arr[],int n){
    int max=INT_MIN;
    for(int i=0;i<n;i++) if(arr[i]>max)max=arr[i];
    for(int pos=1;max/pos>0;pos*=10) countSort(arr,n,pos);   
}
int main(){
    int t;
    cin>>t;
    string ans[t];
    for(int k=0;k<t;k++){
        int n;
        cin>>n;
        char arr[n];
        for(int i=0;i<n;i++) cin>>arr[i];
        int array[n];
        int distinct=0;
        for(int i=0;i<n;i++){
            int a=(int) arr[i];
            bool temp=true;
            for(int j=0;j<distinct;j++){
                if(a==array[j]) temp=false;
            }
            if(temp){
                 array[distinct++]=a;
            }
        
        }
       
        
        radixSort(array,distinct);
        int encryption[26];
        for(int i=0;i<distinct;i++){
            encryption[array[i]-97]=array[distinct-i-1]-97;
        }
        
        string s="";
        for(int i=0;i<n;i++){
            s+=(char) (encryption[(int) arr[i]-97]+97);
        }
        ans[k]=s;
    }
    for(int i=0;i<t;i++){
        cout<<ans[i]<<endl;
    }
}