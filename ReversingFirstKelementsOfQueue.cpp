#include <bits/stdc++.h> 
using namespace std;
queue<int> reverseElements(queue<int> q, int k)
{
    stack<int> s;
    for(int i=0;i<k;i++){
        s.push(q.front());
        q.pop();
    }
    queue<int> q2;
    while(!q.empty()){
        q2.push(q.front());
        q.pop();
    }
    for(int i=0;i<k;i++){
        q.push(s.top());
        s.pop();
    }
    while(!q2.empty()){
        q.push(q2.front());
        q2.pop();
    }
    return q;
}