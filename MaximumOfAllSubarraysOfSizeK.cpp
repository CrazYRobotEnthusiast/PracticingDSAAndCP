#include<bits.stdc++.h>
vector<int> maximumInAllSubarraysOfSizeK(vector<int> arr, int n, int k)
{
  deque<int> q;
  vector<int> v(n-k+1);
  for(int i=0;i<k-1;i++){
    while(!q.empty() and arr[i]>arr[q.back()]) q.pop_back();
    q.push_back(i);
  }
  for(int j=0;j<n-k+1;j++){
    int i=k+j-1;
    while(!q.empty() and q.front()<j) q.pop_front();
    while(!q.empty() and arr[i]>arr[q.back()]) q.pop_back();
    q.push_back(i);
    v[j]=arr[q.front()];
  }
  return v;
}