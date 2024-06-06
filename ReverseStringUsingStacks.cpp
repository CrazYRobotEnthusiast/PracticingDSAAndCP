#include<iostream>
#include<string>
using namespace std;
class Stack{
    public:
    int top;
    int size;
    char *arr;
    Stack(int size){
        this->size=size;
        top=-1;
        arr=new char[size];
    }
    void push(char element){
        if(size-top>1){
            arr[++top]=element;
        }
        else{
            cout<<"Stack OverFlow"<<endl;
        }
        return;
    }
    char pop(){
        if(top>=0){
            return arr[top--];
        }
        else{
            cout<<"Stack UnderFlow"<<endl;
            return -1;
        }
    }
    char peek(){
        if(top>=0){
            return arr[top];
        }
        else{
            cout<<"Stack UnderFlow"<<endl;
            return -1;
        }
    }
    bool isEmpty(){
        if(top==-1){
            return true;
        }
        else{
            return false;
        }
    }

};
int main(){
    cout<<"Enter String to reverse:";
    string s;
    getline(cin,s);
    Stack h= Stack(s.length());
    for (int i=0;i<s.length();i++){
        h.push(s[i]);
    }
    for(int i=0;i<s.length();i++){
        s[i]=h.pop();
        
    }
    cout<<s;

}