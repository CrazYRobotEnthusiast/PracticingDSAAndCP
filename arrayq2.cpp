#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> v;
    char ans='y';
    while (ans=='y'){
        int element;
        cin>>element;
        v.push_back(element);
        cout<<"Enter more elements?";
        cin>>ans;
    }
    cout<<"Enter x:";
    int x;
    cin>>x;
    for (int i=0;i<v.size();i++){
        for(int j=i+1;j<v.size();j++){
            for(int k=j+1;k<v.size();k++){
            if (v[i]+v[j]+v[k]==x){
                cout<<v[i]<<" "<<v[j]<<" "<<v[k]<<endl;
            }
            }
        }
    }

}