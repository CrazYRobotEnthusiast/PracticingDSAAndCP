#include<iostream>
#include<stack>
using namespace std;
class SpecialStack {
    public:
    stack<int> s;
    int Min;
    SpecialStack(){
        Min=INT_MAX;
    }
    void push(int data) {
        if(data>=Min) s.push(data);
        else{
            if(data<Min){
                s.push(2*data-Min);
                Min=data;
            }
        }
    }

    void pop() {
        if(s.top()>=Min){
            int p=s.top();
            s.pop();
            
        }
        else{
            int p=Min;
            Min=2*Min-s.top();
            s.pop();
            
        }
    }

    int top() {
        if (s.top() > Min) {
            return s.top();
        }
        else return Min;
    }

    int getMin() {
        return Min;
    }  
};