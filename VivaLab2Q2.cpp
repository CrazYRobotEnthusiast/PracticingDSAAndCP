#include<iostream>
using namespace std;

void merge(int arr[],int s,int mid,int l,int &c){
    int i=s;
    int j=mid+1;
    int ans[l-s+1];
    int k=0;
    
    while(i<=mid and j<=l){
        if(arr[i]<=arr[j]){
           ans[k++]=arr[i++];
        }
        else{
            ans[k++]=arr[j++];
        }
        c++;
    }
    while(i<=mid) ans[k++]=arr[i++];
    while(j<=l) ans[k++]=arr[j++];
    for(int i=s;i<=l;i++) arr[i]=ans[i-s];
}
void mergeSort(int arr[],int s,int l,int &c){
    if(s>=l) return;
    int mid=(s+l)/2;
    mergeSort(arr,s,mid,c);
    mergeSort(arr,mid+1,l,c);
    merge(arr,s,mid,l,c);
}
int main(){
    int n;
    cout<<"No of elements: ";
    cin>>n;
    cout<<endl<<"Enter the array: ";
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    int comparisons=0;
    mergeSort(arr,0,n-1,comparisons);
    for(int i=0;i<n;i++)cout<<arr[i]<<" ";
    cout<<endl<<"Comparisons="<<comparisons;
}