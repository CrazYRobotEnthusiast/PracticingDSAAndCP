#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
    Node(int d){
        this->data=d;
        this->next=NULL;
    }
};
   Node *A=NULL;
Node *B=NULL;
  Node *C=NULL;
void push(Node *&stackTop,int d){
    if(stackTop==NULL) stackTop=new Node(d);
    else{
    Node *temp=new Node(d);
    temp->next=stackTop;
    stackTop=temp;
    }
}
int pop(Node *&stackTop){
    int a=stackTop->data;
    Node *temp=stackTop;
    stackTop=stackTop->next;
    temp->next=NULL;
    delete temp; 
    return a;   
}
int peek(Node *&stackTop){
    return stackTop->data;
}
void print(Node *&stackTop){
    Node *temp=stackTop;
    while(temp!=NULL){
        cout<<temp->data<<" "<<endl;
        temp=temp->next;
    }
    cout<<endl;
}
void mainPrint(){
        cout<<"A: "<<endl;
        print(A);
        cout<<"B: "<<endl;
        print(B);
        cout<<"C: "<<endl;
        print(C);
        cout<<endl<<endl<<endl;
    return;
}
void towerOfHanoi(Node *&A,Node *&B,Node *&C,int n){
    if(n==1){
        push(C,pop(A));
        mainPrint();
        return;
    }
    towerOfHanoi(A,C,B,n-1);
    towerOfHanoi(A,B,C,1);
    towerOfHanoi(B,A,C,n-1);
}

int main(){
  int n;
  cout<<"Enter no. of discs:";
  cin>>n;
  for(int i=n;i>=1;i--){
    push(A,i);
  }
  towerOfHanoi(A,B,C,n);
}