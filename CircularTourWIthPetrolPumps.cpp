#include <bits/stdc++.h> 
using namespace std;
int firstCircularTour(vector<int>& petrol, vector<int>& distance, int n)
{
	int arr[n];
	for(int i=0;i<n;i++) arr[i]=petrol[i]-distance[i];
	long long front=0;
	long long rear=0;
	long long balance=0;
	long long prevDeficit=0;
	while(front!=n){
		balance+=arr[rear];
		if(balance>=0){
			rear++;
			if(rear==n) break;
			if(front==rear) break;
		}
		else{
			prevDeficit+=balance;
			balance=0;
			front=rear+1;
			rear++;
		}
	}
	
	if(front==n) return -1;
	else if(balance+prevDeficit>=0) return front;
	else return -1;
}