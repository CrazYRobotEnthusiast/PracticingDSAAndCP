#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> a;
    char ans='y';
    while (ans=='y'){
        int element;
        cin>>element;
        a.push_back(element);
        cout<<"Enter more elements?";
        cin>>ans;
    }
    cout<<"Enter value of x:";
    int x;
    cin>>x;
    int i=0;
    int j=a.size()-1;
    int count=0;
    while(i<j){
        if(a[i]+a[j]==x){
            count++;
            i++;
            j--;
        }
        else if(a[i]+a[j]>x){
            j--;
        }
        else{
            i++;
        }
    }
}