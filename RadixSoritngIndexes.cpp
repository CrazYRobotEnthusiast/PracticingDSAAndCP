#include<iostream>
using namespace std;
void countSort(int arr[],int n,int pos,int index[]){
    int freq[10];
    for(int i=0;i<10;i++) freq[i]=0;
    for(int i=0;i<n;i++){
        freq[(arr[i]/pos)%10]++;
    }
    for(int i=1;i<10;i++) freq[i]+=freq[i-1];
    int ans[n];
    int ans2[n];
    for(int i=n-1;i>=0;i--){
        ans[--freq[(arr[i]/pos)%10]]=arr[i];
        ans2[freq[(arr[i]/pos)%10]]=index[i];
    }
    for(int i=0;i<n;i++) {
        arr[i]=ans[i];
        index[i]=ans2[i];
    }
}
void radixSort(int arr[],int n,int index[]){

    int max=INT_MIN;
    for(int i=0;i<n;i++) if(arr[i]>max)max=arr[i];
    for(int pos=1;max/pos>0;pos*=10) countSort(arr,n,pos,index);   
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
    int index[n];
    for(int i=0;i<n;i++) index[i]=i;
    radixSort(arr,n,index);
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    cout<<endl;
    for(int i=0;i<n;i++) cout<<index[i]<<" ";

}