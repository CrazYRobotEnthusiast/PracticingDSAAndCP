#include<iostream>
using namespace std;
class Node{
    public:
    char data;
    Node *next;
    Node(int d){
        this->next=NULL;
        this->data=d;
    }
};
void print(Node *&stackTop){
    Node *temp=stackTop;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
void push(Node *&stackTop,int d){
    if(stackTop==NULL) stackTop=new Node(d);
    else{
        Node *temp=new Node(d);
        temp->next=stackTop;
        stackTop=temp;
    }
}
char pop(Node *&stackTop){
    if(stackTop==NULL){
        return 'h';
    }
    char a=stackTop->data;
    Node *temp=stackTop;
    stackTop=stackTop->next;
    delete temp;
    return a;
}
int main(){
    bool bad=false;
   Node *stack1=NULL;
   char a[1000];
   cin>>a;
   int l=0;
   while(a[l]!='\0'){
    if (a[l]=='(' or a[l]=='[' or a[l]=='{' ){
        push(stack1,a[l]);
    }
    else if(a[l]==')' or a[l]==']' or a[l]=='}'){
        char temp=pop(stack1);
        if (temp=='(' and a[l]==')');
        else if (temp=='{' and a[l]=='}');
        else if (temp=='[' and a[l]==']');
        else{
            bad=true;
            break;
        }
    }
    l++;
   }
   if(bad){
    cout<<"There is problem in given parenthesis";
   }
   else{
    cout<<"Parenthesis pattern is correct";
   }
   
}