#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    vector<vector<int>> v(t);
    vector<int> ans(t);
    for(int k=0;k<t;k++){
        int n;
        cin>>n;
        if(__builtin_popcountll(n)==1){
            ans[k]=1;
            vector<int> a={n};
            v[k]=a;
            continue;
        }
        ans[k]=(__builtin_popcountll(n)+1);
       
        int decimal=n;
        int b=0;
        vector<int> temp;
        int c;
        int f=1;
        do{
            c=decimal%2;
            temp.push_back(c);
            b+=c*f;
            f*=10;
            decimal=decimal/2;
        }while(decimal!=0);
        vector<int> tempAns;

        int size=temp.size();
        for(int i=size-1;i>-1;i--){
            if(temp[i]==1){
                tempAns.push_back(n-pow(2,i));
            }
        }
        tempAns.push_back(n);
        v[k]=tempAns;
        }
        for(int i=0;i<t;i++) {
            
        cout<<ans[i]<<endl;
        for(int j=0;j<v[i].size();j++) cout<<v[i][j]<<" ";
        cout<<endl;
        }
}