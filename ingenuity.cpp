#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    string ans[t];
    for(int k=0;k<t;k++){
        int n;
        cin>>n;
        char charArray[n];
        for(int i=0;i<n;i++) cin>>charArray[i];
        int arr[4];
        for(int i=0;i<4;i++) arr[i]=0;
        for(int i=0;i<n;i++){
            if(charArray[i]=='N')arr[0]++;
            if(charArray[i]=='E')arr[1]++;
            if(charArray[i]=='W')arr[2]++;
            if(charArray[i]=='S')arr[3]++;
        }
        int a[4];
        for(int i=0;i<4;i++) a[i]=arr[i];
        int cancellations=0;
        if(arr[0]>=arr[3]){
            cancellations+=arr[3];
            arr[0]-=arr[3];
            arr[3]=0;
        }
        else{
            cancellations+=arr[0];
            arr[3]-=arr[0];
            arr[0]=0;
        }
        if(arr[1]>=arr[2]){
            cancellations+=arr[2];
            arr[1]-=arr[2];
            arr[2]=0;
        }
        else{
            cancellations+=arr[1];
            arr[2]-=arr[1];
            arr[1]=0;
        }
        if(cancellations==1){
            if(arr[0]==0 and arr[1]==0 and arr[2]==0 and arr[3]==0){
                
                ans[k]="NO";
                continue;
            }
        }
        bool temp=false;
        
        for(int i=0;i<4;i++){
           
            if(arr[i]%2!=0){
                temp=true;
            }
        }
        if(temp){
            
            ans[k]="NO";
            continue;
        }
        int Ncancellations=0;
        int Ecancellations=0;
        if(arr[0]<a[0]){
            Ncancellations= arr[0]==0?a[0]:a[3];
        }
        if(arr[1]<a[1]){
            Ecancellations= arr[1]==0?a[1]:a[2];
        }
        int Rover[4];
        int Helicopter[4];
        for(int i=0;i<4;i++){
            Rover[i]=0;
            Helicopter[i]=0;
        }
        for(int i=0;i<4;i++){
            Rover[i]+=arr[i]/2;
            Helicopter[i]+=arr[i]/2;
        }
        if(Ncancellations%2!=0){
            Helicopter[0]+=Ncancellations%2;
            Helicopter[3]+=Ncancellations%2;
            Rover[0]+=Ncancellations-Ncancellations%2;
            Rover[3]+=Ncancellations-Ncancellations%2;
        }
        else{
            Rover[0]+=Ncancellations/2;
            Rover[3]+=Ncancellations/2;
            Helicopter[0]+=Ncancellations/2;
            Helicopter[3]+=Ncancellations/2;
        }
        if(Ecancellations%2!=0){
            Rover[1]+=Ecancellations%2;
            Rover[2]+=Ecancellations%2;
            Helicopter[1]+=Ecancellations-Ecancellations%2;
            Helicopter[2]+=Ecancellations-Ecancellations%2;
        }
        else{
            Rover[1]+=Ecancellations/2;
            Rover[2]+=Ecancellations/2;
            Helicopter[1]+=Ecancellations/2;
            Helicopter[2]+=Ecancellations/2;
        }
        string s="";
        for(int i=0;i<n;i++){
            int temporary=4;
            if(charArray[i]=='N') temporary=0;
            if(charArray[i]=='E') temporary=1;
            if(charArray[i]=='W') temporary=2;
            if(charArray[i]=='S') temporary=3;
            if(Rover[temporary]!=0){
                s+="R";
                Rover[temporary]--;
            }
            else{
                s+="H";
                Helicopter[temporary]--;
            }
        }
        ans[k]=s;

    }
    for(int i=0;i<t;i++){
        cout<<ans[i]<<endl;
    }
}