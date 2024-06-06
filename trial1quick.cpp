#include<iostream>
using namespace std;
int main(){
    int arr[]={10,9};
    int l=0;
    int r=1;
    int pivot=arr[r];
    for(int i=r-1;i>=l;i--){
        if(arr[i]<pivot) continue;
        int current=arr[i];
        int j=i;
        while(j<r){
            arr[j]=arr[j+1];
            j++;
        }
        arr[r]=current;
    }
    for(int i=0;i<r+1;i++){
        cout<<arr[i]<<" ";
    }

}