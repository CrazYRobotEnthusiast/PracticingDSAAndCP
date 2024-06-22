#include<bits/stdc++.h>
using namespace std;
void countSort(int arr[],int n,int pos,int m[][3]){
    int ans2[n][3];
    int freq[10];
    for(int i=0;i<10;i++) freq[i]=0;
    for(int i=0;i<n;i++){
        freq[(arr[i]/pos)%10]++;
    }
    for(int i=1;i<10;i++) freq[i]+=freq[i-1];
    int ans[n];
    for(int i=n-1;i>=0;i--){
        ans[--freq[(arr[i]/pos)%10]]=arr[i];
        for(int j=0;j<3;j++) ans2[freq[(arr[i]/pos)%10]][j]=m[i][j];
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n-2;j++){
         m[i][j]=ans2[i][j];
        }
    }
    for(int i=0;i<n;i++){

     arr[i]=ans[i];

     
     }

}
void radixSort(int arr[],int n,int m[][3]){
    int max=INT_MIN;
    for(int i=0;i<n;i++) if(arr[i]>max)max=arr[i];
    for(int pos=1;max/pos>0;pos*=10) countSort(arr,n,pos,m);   
}
int main(){
    int t;
    cin>>t;
    long long int ans[t];
    for(int k=0;k<t;k++){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++) cin>>arr[i];
        int m[n-2][3];
        for(int i=0;i<n-2;i++){
            m[i][0]=arr[i];
            m[i][1]=arr[i+1];
            m[i][2]=arr[i+2];
        }
        long long int count=0;
        int a1[n-2];
        for(int i=0;i<n-2;i++) a1[i]=m[i][0];
        radixSort(a1,n-2,m);
        int a2[n-2];
        for(int i=0;i<n-2;i++) a2[i]=m[i][1];
        int a3[n-2];
        for(int i=0;i<n-2;i++) a3[i]=m[i][2];
        radixSort(a2,n-2,m);
        for(int i=0;i<n-2;i++){
            for(int j=0;j<3;j++) cout<<m[i][j]<<" ";
            cout<<endl;
        }
        cout<<endl;
        for(int i=0;i<n-2;i++){
            if(m[i][1]==m[i+1][1]){   
                 int j=i+1;
                 while( j<n-2 and m[i][1]==m[j][1]){
                    if(m[i][0]==m[j][0] and m[i][1]==m[j][1] and m[i][2]!=m[j][2]) count++;
                    j++;
                 }
            }
        }
        radixSort(a3,n-2,m);
        for(int i=0;i<n-2;i++){
            for(int j=0;j<3;j++) cout<<m[i][j]<<" ";
            cout<<endl;
        }
        cout<<endl;
        for(int i=0;i<n-2;i++){
            
             if(m[i][2]==m[i+1][2]){   
                 int j=i+1;
                 while( j<n-2 and m[i][2]==m[j][2]){
                    if(m[i][0]!=m[j][0] and m[i][1]==m[j][1] and m[i][2]==m[j][2]) count++;
                    j++;
                 }
            } 
        }
        radixSort(a1,n-2,m);
        for(int i=0;i<n-2;i++){
            for(int j=0;j<3;j++) cout<<m[i][j]<<" ";
            cout<<endl;
        }
        cout<<endl;
        for(int i=0;i<n-2;i++){
            if(m[i][0]==m[i+1][0]){   
                 int j=i+1;
                 while( j<n-2 and m[i][0]==m[j][0]){
                    if(m[i][0]==m[j][0] and m[i][1]!=m[j][1] and m[i][2]==m[j][2]) count++;
                    j++;
                 }
            }   
        }
        ans[k]=count;
    }
    for(int i=0;i<t;i++) cout<<ans[i]<<endl;
}