#include<iostream>
#include <bits/stdc++.h>
using namespace std;
int main(){
    
    cout<<"Enter the sentence: ";
    string s;
    getline(cin,s);
    int n=s.length();
    int numWords=0;
    int current=0;
    int max=0;
    for(int i=0;i<n;i++){
        if(s[i]==' '){
            numWords++;
            if(current>max) max=current;
            current=0;
        }
        else{
            current++;

        }
    }
    numWords++;
    if(current>max) max=current;
    char arr[numWords][max];
    int j=0;
    int k=0;
    for(int i=0;i<n;i++){
        if(s[i]==' '){
        j++;
        if(k<max-1){
            while(k<=max-1){
                k++;
                arr[j][k]=' ';
            }

        }
        k=0;
        }
        else{
          arr[j][k]=s[i];
          k++;
        }
    }
    for(int j=0;j<numWords;j++){
        for(int k=0;k<max;k++){
            cout<<arr[j][k]<<" ";
        }
        cout<<endl;
    }

}