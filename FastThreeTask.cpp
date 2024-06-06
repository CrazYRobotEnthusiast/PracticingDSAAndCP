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
        int sum=0;
        int n1=0;
        int n2=0;
        for(int j=0;j<n;j++){
            int a;
            cin>>a;
            sum+=a;

            if(a%3==0){

            }
            else if(a%3==1){
                n1++;
            }
            else{
                n2++;
            }
        }
        if(sum%3==0) ans[i]=0;
        else if(sum%3==1 and n1>=1) ans[i]=1;
        else if(sum%3==2) ans[i]=1;
        else ans[i]=2;
    }
    for(int i=0;i<alpha;i++){
        cout<<ans[i]<<endl;
    }
}