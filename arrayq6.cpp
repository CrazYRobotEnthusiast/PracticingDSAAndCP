#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> a;
    char ans='y';
    while (ans=='y'){
        int element;
        cin>>element;
        a.push_back(element);
        cout<<"Enter more elements?";
        cin>>ans;
    }
    cout<<"Enter value of x:";
    int x;
    cin>>x;
    int left_ptr=0;
    int right_ptr=a.size()-1;
    bool f=false;
    while(left_ptr<right_ptr){
        if (a[left_ptr]+a[right_ptr]<x) left_ptr++;
        else if(a[left_ptr]+a[right_ptr]<x) right_ptr--;
        else{
           f=true;
           break;
        }
    }
    switch(f){
        case true:
        cout<<"Yes";
        break;
        case false:
        cout<<"No";
        break;
    }
}
    
    