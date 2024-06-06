#include<iostream>
using namespace std;
int binarySearch(int arr[],int n,int key){
    int center=n/2;
    if(arr[center]==key) return center;
    else if(arr[center]>key){
        int a[center];
        for(int i=0;i<center;i++) a[i]=arr[i];
        return binarySearch(a,center,key);
    }
    else{
        int a[n-center-1];
        for(int i=center+1;i<n;i++) a[i-center-1]=arr[i];
        return center+1+binarySearch(a,n-center-1,key);
    }
}
int main(){
    int arr[]={1,3,5,7,9,11};
    cout<<binarySearch(arr,6,9);
}