#include <iostream>
using namespace std;

int main()  {
  int arr[]={0,1,55,2,0,0,0,22,3,4,0};
  int n=11;
  for(int i=0;i<n;i++){
    for(int j=0;j<n-i;j++){
        if(arr[j]==0 and arr[j+1]!=0)
        swap(arr[j],arr[j+1]);
    }
    for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
  }
  }
  for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
  }
}