#include<bits/stdc++.h>
using namespace std;
void countSort(int arr[],int n){
    //Finding max element in array
    int max=arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]>max) max=arr[i];
    }
    //Making frequency array
    int frequencyArray[max+1];
    for(int i=0;i<max+1;i++){
        frequencyArray[i]=0;
    }
    for(int i=0;i<n;i++){
        frequencyArray[arr[i]]++;
    }
    
    //Making frequency array into cumulative frequency array

    for(int i=1;i<max+1;i++){
        frequencyArray[i]=frequencyArray[i]+frequencyArray[i-1];
    }
    //Making ans array
    int ans[n];
    for(int i=n-1;i>=0;i--){
        ans[--frequencyArray[arr[i]]]=arr[i];
    }
    //Copying ans array in original array
    for(int i=0;i<n;i++){
        arr[i]=ans[i];
    }
}
int main(){
    int arr[]={5,2,3,2,1,7,3,4,5,11};
    countSort(arr,11);
    for(int i=0;i<11;i++){
        cout<<arr[i]<<" ";
    }

}