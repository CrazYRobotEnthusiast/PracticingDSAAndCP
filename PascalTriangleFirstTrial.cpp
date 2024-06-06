#include<iostream>
#include<vector>
using namespace std;
int f(int a){
    int f=1;
    for(int i=1;i<=a;i++){
        f*=i;
    }
    return f;
}
int main(){
   int n;
   cout<<"Enter no. of rows:";
   cin>>n;
   vector<vector<int>> a(n);
   for(int i=0;i<n;i++){
    a[i].resize(i+1);
   }

   for(int i=0;i<n;i++){
    for(int j=0;j<=i;j++){
        a[i][j]= f(i)/(f(i-j)*f(j));
    }
   }
   for(int i=0;i<n;i++){
    for(int j=0;j<=i;j++){
        cout<<a[i][j]<<" ";
    }
    cout<<endl;
   }

}