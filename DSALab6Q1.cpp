#include<iostream>
using namespace std;
int partition(int l,int r, int arr[]){
    int pivot=arr[r];
    int i=l-1;
    for(int j=l;j<=r;j++){
        if (arr[j]<=pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    return i;
}
void QuickSort(int l,int r, int arr[]){
    if(l>=r) return;
    
    int pi=partition(l,r,arr);
    cout<<endl;
    QuickSort(l,pi-1,arr);
    QuickSort(pi+1,r,arr);
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
    QuickSort(0,n-1,arr);
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
}