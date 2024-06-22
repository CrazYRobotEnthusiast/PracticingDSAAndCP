#include<iostream>
using namespace std;
void countSort(long long int arr[],int n,int pos){
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
void radixSort(long long int arr[],int n){
    int max=INT_MIN;
    for(int i=0;i<n;i++) if(arr[i]>max)max=arr[i];
    for(int pos=1;max/pos>0;pos*=10) countSort(arr,n,pos);   
}
int main(){
    long long int t;
    cin>>t;
    int b[t];
    bool ans[t];
    bool temp=true;
    for(int k=0;k<t;k++){
        int n;
        cin>>n;
        long long int originalArr[n];
        long long int newArr[n];
        for(int i=0;i<n;i++) cin>>originalArr[i];
        for(int i=0;i<n;i++) cin>>newArr[i];
        long long int m;
        cin>>m;
        long long int mod[m];
        for(int i=0;i<m;i++) cin>>mod[i];
        bool assume=true;
        long long int changes[m];
        int p1=0;
        for(int i=0;i<n;i++){
            if(originalArr[i]!=newArr[i]){
                if(p1>=m) {
                    assume =false;
                    break;}
                changes[p1]=newArr[i];
                p1++;
            }
        }
        if(!assume){
            ans[k]=assume;
            
            continue;
        }
        assume=false;
        
        for(int i=0;i<n;i++){
            if(newArr[i]==mod[m-1]) assume=true;   
        }

        if(!assume){
            ans[k]=assume;
            

            continue;
        }
        radixSort(changes,p1);
        radixSort(mod,m);
        int i=0;
        int j=0;
        assume=true;
        while(i<p1 and j<m){
            if(changes[i]==mod[j]){
                i++;
                j++;
            }
            else if(changes[i]<mod[j]){
                assume=false;
                break;
            }
            else{
                j++;
            }
        }
        if(!assume) {
            ans[k]=assume; 
            
            continue;
        }
        
        if(j>=m and i<p1) assume=false;
        else assume=true;
        ans[k]=assume;
    }
    
    for(int i=0;i<t;i++){
        if(ans[i]) cout<<"YES";
        else cout<<"NO";
        cout<<endl;
    }
    
    return 0;
}