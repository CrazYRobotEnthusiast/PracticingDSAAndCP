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
    cout<<"Enter k:";
    int k;
    cin>>k;
    while (k>v.size()){
       k-=v.size();
    }
    vector<int> a;
    for (int i=v.size()-k;i<v.size();i++){
        a.push_back(v[i]);
    }
    for (int i=0;i<v.size()-k;i++){
        a.push_back(v[i]);
    }

    
}