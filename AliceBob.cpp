#include<iostream>
#include<string>
using namespace std;
const char * winning(int a,int b,int turn){ 
   if(b>a){
      if((b-a)%2==0) return "Bob";
      else return "Alice";
   }
   else if(a>b){
      if((a-b)%2!=0) return "Alice";
      else return "Bob";
   }
   else{
    return "Bob";

   }
}
int main(){
    int n;
    cin>>n;
    int arr[2*n];
    for(int i=0; i<2*n;i++){
        cin>>arr[i];
    }
    for(int i=0; i<2*n;i+=2){
        cout<<winning(arr[i],arr[i+1],1)<<endl;
    }
}