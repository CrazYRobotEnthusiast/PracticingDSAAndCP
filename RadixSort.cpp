#include<iostream>
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
    int n;
    cout<<"Enter number of elements:";
    cin>>n;
    int arr[n];
    cout<<"Enter list: ";
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        arr[i]=a;
    }
    radixSort(arr,n);
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
}