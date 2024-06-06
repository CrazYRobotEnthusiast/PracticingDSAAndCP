#include<iostream>
#include<vector>
using namespace std;
int largestRectangle(vector < int > & heights) {
     int maxArea=0;
     for(int i=0;i<heights.size();i++){
       int currArea=0;
       for(int j=i;j>-1;j--){
         if(heights[j]<heights[i]) break;
         currArea+=heights[i];
       }
       for(int j=i+1;j<heights.size();j++){
         if(heights[j]<heights[i]) break;
         currArea+=heights[i];
       }
       if(currArea>maxArea) maxArea=currArea;
     }
     return maxArea;
 }
 int main(){
    
 }