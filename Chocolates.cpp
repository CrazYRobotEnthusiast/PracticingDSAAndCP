#include<iostream>
#include<vector>
using namespace std;
bool ableToDistribute(vector <int> v, int k, int n){
     int j=0;
     int current=0;
     int i=1;
     while(i<=k and j<v.size()){
        if(current+v[j]<=n){
            current+=v[j];
            j++;
        }
        else{   
            i++;
            current=0;
        }  
     }
     if(j==v.size()) return 1;
     else return 0;
}
int choosingToDistribute(vector<int> v,int k){
    int s=v[0];
    int e=0;
    for(int i=0;i<v.size();i++){
        e+=v[i];
        if(s<v[i]) s=v[i];
    }
    int mid;
    int ans;
    while(s<=e){
        mid=(s+e)/2;
        if(ableToDistribute(v,k,mid)){
            ans=mid;
            e=mid-1;
        }
        else{
            s=mid+1;
        }
        
    }
    return ans;
}
int main(){
    int num;
    cout<<"Enter number of chocolates: ";
    cin>>num;
    vector<int> v;
    for(int i=0;i<num;i++){
        int a;
        cin>>a;
        v.push_back(a);
    }
    cout<<"Enter number of students ";
    int x;
    cin>>x;
    cout<<choosingToDistribute(v,x);

}