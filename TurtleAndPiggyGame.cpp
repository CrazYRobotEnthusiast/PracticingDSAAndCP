#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    int ans[t];
    for(int i=0;i<t;i++){
        long long int l;
        long long int r;
        cin>>l;
        cin>>r;
        int c=0;
        while(r>=1){
            c++;
            r/=2;
        }
        ans[i]=--c;
    }
    for(int i=0;i<t;i++){
        cout<<ans[i]<<endl;
    }
}