#include<iostream>
#include<vector>
using namespace std;

void f(string s,int idx,string temps,vector<string> &v){
    if (idx==s.length()){
        if(temps=="") return;
        v.push_back(temps);
        return;
    }
    f(s,idx+1,temps+s[idx],v);
    f(s,idx+1,temps,v);
}
int main(){
    string s;
    cin>>s;
    vector<string> v;
    f(s,0,"",v);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
}