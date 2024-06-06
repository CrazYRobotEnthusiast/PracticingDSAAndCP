#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> a1={1,2,3,7};
    vector<int> a2={4,5,8};
    vector<int> alpha(a1.size()+a2.size());
    int i=0;
    int j=0;
    for (int r=0;r< alpha.size();r++){
        if (i<a1.size()&&j<a2.size()){
        if (a1[i]<=a2[j]){
            alpha[r]=a1[i];
            i++;
        }
        else{
            alpha[r]=a2[j];
            j++;
        }
    }
    else if(i>=a1.size()){
        alpha[r]=a2[j];
        j++;
    }
    else{
        alpha[r]=a1[i];
        i++;
    }
    }
    for (int element:alpha){
        cout<<element<<" ";
    }
}