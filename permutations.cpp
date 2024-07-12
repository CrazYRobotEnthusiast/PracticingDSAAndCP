#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    vector<vector<int>> v;
    for(int i=0;i<t;i++){
        int n,m,k;
        cin>>n>>m>>k;
        vector<int> v_small;
        if(n<k){
            for(int i=1;i<=n;i++) v_small.push_back(i);
        }
        else{
            for(int i=n;i>=k;i--) v_small.push_back(i);
            for(int i=m+1;i<k;i++) v_small.push_back(i);
            for(int i=1;i<=m;i++) v_small.push_back(i);

        }
        v.push_back(v_small);
    }
    for(int i=0;i<t;i++){
        for(int j=0;j<v[i].size();j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    
}