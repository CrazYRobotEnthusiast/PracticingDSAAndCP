#include <bits/stdc++.h> 
#include<stack>
using namespace std;
/*
	This is signature of helper function 'knows'.
	You should not implement it, or speculate about its implementation.

	bool knows(int A, int B); 
	Function 'knows(A, B)' will returns "true" if the person having
	id 'A' know the person having id 'B' in the party, "false" otherwise.
*/
bool knows(int A,int B){
    return true; //This is not the correct knows function...some method should be given in question.
}

int findCelebrity(int n) {
    stack <int> s;
	for(int i=0;i<n;i++) s.push(i);
	while(s.size()>1){
		int a=s.top();
		s.pop();
		int b=s.top();
		s.pop();
		if(knows(a,b) and !knows(b,a)) s.push(b);
		if(knows(b,a) and !knows(a,b)) s.push(a);

	}
	if(s.empty()) return -1;
	int c=s.top();
	bool trial=true;
	for(int i=0;i<n;i++){
		if(i==c) continue;
		if(knows(c,i)) trial=false;
		if(!knows(i,c)) trial=false;
	}
	if(trial) return c;
	return -1;
}