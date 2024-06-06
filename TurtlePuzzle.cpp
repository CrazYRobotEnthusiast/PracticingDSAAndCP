#include<iostream>
using namespace std;
int main(){
    int alpha;
    cin>>alpha;
    int ans[alpha];
    for(int i=0;i<alpha;i++){
        int n;
        cin>>n;
        ans[i]=0;
        for(int j=0;j<n;j++){
            int a;
            cin>>a;
            ans[i]+=abs(a);
        }

    }
    for(int i=0;i<alpha;i++){
        cout<<ans[i]<<endl;
    }
}