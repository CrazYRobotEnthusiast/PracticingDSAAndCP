#include<iostream>
using namespace std;
int main(){
   int x;
   cout<<"Enter number of days:";
   cin>>x;
   int years=0;
   while((years%4!=0 and x>=365) or (years%4==0 and x>=366)){
    if(years%4==0){ 
        if(years%100==0){
            x-=365;
            }
        else{
            x-=366;
        }
            }
    else x-=365;
    years+=1;
   }
   int months=0;
   int arr[]={31,28,31,30,31,30,31,31,30,31,30,31};
   if(years%4==0 and years%100!=0) arr[1]=29; 
   int i=0;
   while(x>arr[i]){
    x-=arr[i];
    months+=1;
    i++;
   }
   cout<<years<<" years "<<months<<" months "<<x<<" days"<<endl;
   if(years%4==0) cout<<"It is a leap year";
   else cout<<"It is not a leap year";
}