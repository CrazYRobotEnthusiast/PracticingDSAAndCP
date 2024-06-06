#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    int ans[t];
    for(int i=0;i<t;i++){
        ans[i]=0;
        int m;
        int n;
        cin>>n>>m;
        char given[n];
        cin>>given;
        int array[7];
        for(int i=0;i<7;i++) array[i]=0;
        for(int i=0;i<n;i++){
            array[int(given[i])-65]++;
        }
        for(int j=0;j<7;j++){
            if(array[j]<m){
                ans[i]+=(m-array[j]);
            }
        }
    }
    for(int i=0;i<t;i++){
        cout<<ans[i]<<endl;
    }
    return 0;
}