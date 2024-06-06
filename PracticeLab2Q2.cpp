#include<iostream>
using namespace std;
void merge(int a[],int s,int mid,int e){
   int ans[e-s+1];
   int i=s;
   int j=mid+1;
   int k=0;
   while(i<=mid and j<=e){
    if(a[i]<a[j]){
       ans[k++]=a[i++];
    }
    else if(a[j]<=a[i]){
        ans[k++]=a[j++];
    }

   }
   while(i<=mid){
    ans[k++]=a[i++];
   }                
   while(j<=e){
    ans[k++]=a[j++];
   }                
   for(int i=s;i<=e;i++){
    a[i]=ans[i-s];
   }              
}
void mergeSort(int a[],int s,int e){
    if(s>=e) return;
    int mid=(s+e)/2;
    mergeSort(a,s,mid);
    mergeSort(a,mid+1,e);
    merge(a,s,mid,e);
}
int main(){
    int a[]={2,4,3,1,6};
    mergeSort(a,0,4);
    for(int i=0;i<5;i++){
        cout<<a[i];
    }
}
