#include<bits/stdc++.h>
using namespace std;
int main(){
    set<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(4);
    s.insert(5);
    auto it=s.lower_bound(2);
    cout<<*it;
    auto it2=s.upper_bound(2);
    cout<<*it;
    int num=7;
    int cnt=__builtin_popcountll(num);
    cout<<cnt;
}