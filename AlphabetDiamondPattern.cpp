#include<iostream>
using namespace std;
int main(){
    int r;
    cout<<"Enter n: ";
    cin>>r;
    for (int i=1;i<=2*r-1;i++){
        for( int j=1;j<=2*r-1;j++){
            if (i<=r){
                if(j>=r-i+1&&j<=r+i-1){
                    int x=j-r+i-1+'A';
                    cout<<(char)x;
                    
                }
                else{
                    cout<<" ";
                }
            }
            else{
                if(j>=i-r+1&&j<=3*r-i-1){
                    int x='A'+j+r-i-1;
                    cout<<(char)x;

                }
                else{
                    cout<<" ";
                }
            }

        }
        cout<<endl;
    }
}
    