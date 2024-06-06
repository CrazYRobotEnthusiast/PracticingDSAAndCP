#include <iostream>
using namespace std;

int main() 
{
  int arr[]={0,1,55,2,0,0,0,22,3,4,0};
  int n=11;
  for(int i=n-1;i>=0;i--){
    if(arr[i]!=0) continue;
    int j=i;
    while(j<n-1 and arr[j+1]!=0){
      arr[j]=arr[j+1];
      j++;
    }
    if(j<n) arr[j+1]=0;
  for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
  }
  cout<<endl;
    
  }
  for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
  }
}