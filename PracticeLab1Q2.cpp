#include<iostream>
using namespace std;
void insertion(int arr[],int n){
    for(int i=1;i<n;i++){
        int key=arr[i];
        int j=i-1;
        while(j>=0 and arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}
int main(){
   int a[]={3,4,1,2,6};
   insertion(a,5);
   for(int i=0;i<5;i++){
    cout<<a[i];
   }
   }