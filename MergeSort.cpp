#include<iostream>
using namespace std;
void merge(int arr[], int l, int mid, int r) {
    int n1 = mid - l + 1;
    int n2 = r - mid;

    int a[n1], b[n2];

    for (int i = l; i <=mid; i++) {
        a[i-l] = arr[i];
    }
    for (int i = mid+1; i <= r; i++) {
        b[i-mid-1] = arr[i];
    }

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (a[i] <= b[j]) {
            arr[k] = a[i];
            i++;
        } else {
            arr[k] = b[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = a[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = b[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[],int l,int r){
    if(l==r) return;
    int mid=(l+r)/2;
    mergeSort(arr,l,mid);
    mergeSort(arr,mid+1,r);
    merge(arr,l,mid,r);
}

int main(){
  int arr[]={1,33,2,4,55,6,7};
  mergeSort(arr,0,6);
  for(int i=0;i<7;i++){
    cout<<arr[i]<<" ";
  }
}