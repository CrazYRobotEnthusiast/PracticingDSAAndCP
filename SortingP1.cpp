//Find the kth smallest element in an array
#include<iostream>
using namespace std;
int Kth(int arr[],int k,int first,int last){
    int pivot=arr[last];
    int i=first;
    int j=last;
    while(i<j){
        if(arr[i]>pivot and arr[j]<pivot){
            swap(arr[i],arr[j]);
        }
        else if(arr[i]<=pivot){
            i++;
        }
        else if(arr[j]>=pivot){
            j--;
        }
    }
    swap(arr[i],arr[last]);
    if(i==k-1) return arr[i];
    else if(i<k-1) return Kth(arr,k,i+1,last);
    else return Kth(arr,k,first,i-1);
}
int main(){
int arr[]={3,5,7,2,3,8,9};
cout<<Kth(arr,4,0,6);
}