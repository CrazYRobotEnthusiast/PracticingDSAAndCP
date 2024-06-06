#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"No of elements: ";
    cin>>n;
    cout<<endl<<"Enter the array: ";
    int arr[n];
    int comparisons=0;
    int swaps=0;
    for(int i=0;i<n;i++) cin>>arr[i];
    for(int i=1;i<n;i++){
        int key=arr[i];
        int j=i-1;
        while(arr[j]>key and j>=0){
            arr[j+1]=arr[j];
            j--;
            comparisons++;
        }
        comparisons++;
        arr[j+1]=key;
        if(j+1!=i) swaps++;

    }
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    cout<<endl<<"Swaps="<<swaps<<endl<<"Comparisons="<<comparisons;
}