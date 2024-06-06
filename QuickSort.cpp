#include<iostream>
using namespace std;

int partition(int arr[],int l,int r){
    int pivot=arr[r];
    int i=l-1;
    for(int j=l;j<=r;j++){
        if(arr[j]<=pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    return i;
}
void quickSort(int arr[],int l,int r){
    if(l>=r) return;
    int correctPivotPlace=partition(arr,l,r);

    quickSort(arr,l,correctPivotPlace-1);
    
    quickSort(arr,correctPivotPlace+1,r);
}
int main(){
    int arr[]={10,3,7,9,1,8};

    quickSort(arr,0,5);
    for(int i=0;i<6;i++){
        cout<<arr[i]<<" ";
    }
}