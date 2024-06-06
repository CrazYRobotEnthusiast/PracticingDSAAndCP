#include<vector>
#include<stack>
#include<iostream>
using namespace std;
//next Smallest element for an array element is the first element which is strictly smaller as we move to the right of the array element.
//Note: given code will give us index of the next smallest elements.
vector <int> nextSmallest(vector<int> arr){
    vector<int> v(arr.size());
    stack<int> s;
    s.push(arr.size());
    for(int i=arr.size()-1;i>-1;i--){
        if(s.top()==arr.size()){
             v[i]=s.top();
             s.push(i);
              
            }
        else if(arr[s.top()]<arr[i]){
            v[i]=s.top();
            s.push(i);
        }
        else{
            while(arr[s.top()]>=arr[i]){
                s.pop();
                if(s.top()==arr.size()) break;
            }
            v[i]=s.top();
              s.push(i);
        }
    }
    return v;
}