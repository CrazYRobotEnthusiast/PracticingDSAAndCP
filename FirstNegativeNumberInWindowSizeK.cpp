#include <bits/stdc++.h> 
#include<queue>
using namespace std;
vector<int> firstNegativeInteger(vector<int> &arr, int k, int n)
{
   int windows=n-k+1;
   vector<int> v(windows);
   deque<int> q;
   for(int i=0;i<k-1;i++) q.push_back(arr[i]);
   for(int j=0;j<windows;j++){
       q.push_back(arr[k-1+j]);
       if(q.size()>k) q.pop_front();
       while(!q.empty() and q.front()>=0) q.pop_front();
       if(q.empty()) v[j]=0;
       else v[j]=q.front();
   }
   return v;

}
