#include<bits/stdc++.h>
using namespace std;
long long int f(long long int a,long long int b){
    if (a>b) swap(a,b);
    return (b%a==0)?a:f(a,b%a);
}
bool check(vector<int> v){
    for(int i=1;i<v.size();i++){
        if(v[i]<v[i-1]) return false;
    }
    return true;
}
int main(){
    int t;
    cin>>t;
    bool ans[t];
    for(int k=0;k<t;k++){
        long long int n;
        cin>>n;
        long long int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int count=0;
        vector<int> v1;
        vector<int> v2;
        vector<int> v3;
        v1.push_back(f(arr[0],arr[1]));
        v2.push_back(f(arr[0],arr[1]));
        v3.push_back(f(arr[0],arr[1]));
        int j;
        bool temp=true;
        for(int i=1;i<n-1;i++){
            int a=f(arr[i],arr[i+1]);
            if(a>=v1[v1.size()-1]){
                v1.push_back(a);
                v2.push_back(a);
                v3.push_back(a);
            }
            else{
                temp=false;
                j=i;
                break;
            }
        }
        if(temp){
            ans[k]=temp;
            continue;
        }
        v1.pop_back();
        v2.pop_back();
        v2.push_back(f(arr[j-1],arr[j+1]));
    
        if(j!=1){
        v1.pop_back();
        v1.push_back(f(arr[j-2],arr[j]));
        }
        v1.push_back(f(arr[j],arr[j+1])); 
       if(j+2<n){
        v1.push_back(f(arr[j+1],arr[j+2]));
        v2.push_back(f(arr[j+1],arr[j+2]));
        v3.push_back(f(arr[j],arr[j+2]));
       }
       for(int i=j+2;i<n-1;i++){
        v1.push_back(f(arr[i],arr[i+1]));
        v2.push_back(f(arr[i],arr[i+1]));
        v3.push_back(f(arr[i],arr[i+1]));
       }
       temp=check(v1) or check(v2) or check(v3);
       ans[k]=temp;   
    }
    for(int i=0;i<t;i++){
        if(ans[i]) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}