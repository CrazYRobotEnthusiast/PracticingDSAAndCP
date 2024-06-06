#include<stack>
#include<vector>
#include<iostream>
using namespace std;
vector <int> prevSmallest(vector<int> arr){
    vector<int> v(arr.size());
    stack<int> s;
    s.push(-1);
    for(int i=0;i<arr.size();i++){
        
        if(s.top()==-1){
            
            v[i]=-1;
              s.push(i);
              
            }
        else if(arr[s.top()]<arr[i]){
            
            v[i]=s.top();
            s.push(i);
        }
        else{
            while(arr[s.top()]>=arr[i]){
                s.pop();
                if(s.top()==-1) break;
            }
              v[i]=s.top(); 
              s.push(i);       
        }
    }
    return v;
}
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
int largestRectangle(vector < int > & heights) {
	vector<int> v1=prevSmallest(heights);
	vector<int> v2=nextSmallest(heights);
	int maxArea=0;
	for(int i=0;i<heights.size();i++){
		int width=v2[i]-v1[i]-1;
		int currArea=width*heights[i];
		if(currArea>maxArea) maxArea=currArea;
	}
	return maxArea;
}

