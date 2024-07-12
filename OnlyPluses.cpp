#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    long long int ans[t];
    for(int k=0;k<t;k++){
        long long int a,b,c;
        cin>>a>>b>>c;
        for(int i=0;i<5;i++){
            if(a<=b and a<=c) a++;
            else if(b<=a and b<=c) b++;
            else if(c<=b and c<=a) c++;
        }
        ans[k]=a*b*c;
    }
    for(int i=0;i<t;i++) cout<<ans[i]<<endl;
}