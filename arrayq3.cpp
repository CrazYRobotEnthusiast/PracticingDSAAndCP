#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> v;
    char ans='y';
    while (ans=='y'){
        int element;
        cin>>element;
        v.push_back(element);
        cout<<"Enter more elements?";
        cin>>ans;
    }
    int a=-1;
    int b=-1;
    for (int element: v){
        if (element>a){
            b=a;
            a=element;
        }
        if (element>b && element<a){
            b=element;
        }
    }
    cout<<b;

    }
    
