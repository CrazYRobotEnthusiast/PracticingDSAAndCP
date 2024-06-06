#include<iostream>
using namespace std;
class Node{
    public:
    int index;
    int data;
    Node *next;
    Node(int index,int d){
        this->index=index;
        this->data=d;
        this->next=NULL;
    }
};
void insertAtTail(Node *&tail,int index,int d){
    if (tail==NULL) tail=new Node(index,d);
    else{
        Node *temp=new Node(index,d);
        tail->next=temp;
        tail=temp;
    }
}
void print(Node *&head){
    Node *temp=head;
    while(temp!=NULL){
        cout<<temp->index<<':'<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main(){
    cout<<"Enter the dimensions of the matrices: ";
    int r1,c1;
    cin>>r1>>c1;
    int mat1[r1][c1];
    cout<<"Enter values of mat 1:-";
    for(int i=0;i<r1;i++){
       for(int j=0;j<c1;j++){
        cin>>mat1[i][j];
        }
    }
    Node *matrix1[r1];
    for(int i=0;i<r1;i++){
        matrix1[i]=NULL;
    }
    Node *tails[r1];
    for(int i=0;i<r1;i++){
        tails[i]=NULL;
    }
    for(int i=0;i<r1;i++){
        for(int j=0;j<c1;j++){
            if (mat1[i][j]!=0){
                if (matrix1[i]==NULL){
                    matrix1[i]=new Node(j,mat1[i][j]);
                    tails[i]=matrix1[i];
                }
                else{
                    insertAtTail(tails[i],j,mat1[i][j]);
                }
            }
        }
    }
    for(int i=0;i<r1;i++){
        print(matrix1[i]);
    }
}