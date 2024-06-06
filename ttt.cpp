#include<vector>
#include<iostream>
using namespace std;
int partition(vector<float> arr,int l,int r){
    float pivot=arr[r];
    int j=l-1;
    for(int i=l;i<=r;i++){
        if(arr[i]<=pivot) swap(arr[i],arr[++j]);
    }
    return j;
}
void quickSort(vector<float> arr,int l,int r){
    if(l>=r) return;
    int pi=partition(arr,l,r);
    quickSort(arr,l,pi-1);
    quickSort(arr,pi+1,r);
}
void bucketSort(float arr[],int size){
    vector<vector<float>> bucket(size,vector<float>());
    for(int i=0;i<size;i++){
        int index=arr[i]*size;
        bucket[index].push_back(arr[i]);
    }
    for(int i=0;i<size;i++){
        quickSort(bucket[i],0,bucket[i].size()-1);
    }
    int k=0;
    for(int i=0;i<size;i++){
        for(int j=0;j<bucket[i].size();j++){
            arr[k]=bucket[i][j];
            k++;
        }
    }
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
}
int main(){
    int n;
    cout<<"Enter number of elements:";
    cin>>n;
    float arr[n];
    cout<<"Enter list: ";
    for(int i=0;i<n;i++){
        float a;
        cin>>a;
        arr[i]=a;
    }

    bucketSort(arr,n);

}