#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    int index;
    Node *next;
    Node *prev;
    Node(int d,int index){
        this->index=index;
        this->data=d;
        this->next=NULL;
        this->prev=NULL;
    }
};
void insertAtTail(Node *&tail,int index,int d){
    if(tail==NULL) tail= new Node(d,index);
    else{
        Node *temp=new Node(d,index);
        tail->next=temp;
        tail=temp;
    }
    return;
}
void print(Node *&head){
    Node *temp=head;
    while(temp!=NULL){
        cout<<temp->index<<": "<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main(){
    int r1,c1,r2,c2;
    cout<<"Enter the dimensions of the two matrices: ";
    cin>>r1>>c1>>r2>>c2;
    if(c1!=r2){
        cout<<"Given matrix dimensions can't be multiplied";
    }
    else{
        Node *mat1[r1];
        Node *tails1[r1];
        for(int i=0;i<r1;i++){ 
            mat1[i]=NULL;
            tails1[i]=NULL;
        }
        for(int i=0;i<r1;i++){
            for(int j=0;j<c1;j++){
                int a;
                cin>>a;
                if(a!=0){
                    if(mat1[i]==NULL){
                        mat1[i]=new Node(a,j);
                        tails1[i]=mat1[i];
                    }
                    else{
                        insertAtTail(tails1[i],j,a);
                    }
                }
            }
        }
        Node *mat2[c2];
        Node *tails2[c2];
        for(int i=0;i<c2;i++){ 
            mat2[i]=NULL;
            tails2[i]=NULL;
        }
        for(int i=0;i<r2;i++){
            for(int j=0;j<c2;j++){
                int a;
                cin>>a;
                if(a!=0){
                    if(mat2[j]==NULL){
                        mat2[j]=new Node(a,i);
                        tails2[j]=mat2[j];

                    }
                    else{
                        insertAtTail(tails2[j],i,a);
                    }
                }
            }
        }
        cout<<"ANS:"<<endl;
        Node *ans[r1];
        Node *tailsAns[r1];
        for(int i=0;i<r1;i++){ 
            ans[i]=NULL;
            tailsAns[i]=NULL;
        }
        for(int i=0;i<r1;i++){
            for(int j=0;j<c2;j++){
                int val=0;
                Node *tempHead1=mat1[i];
                Node *tempHead2=mat2[j];
                while(tempHead1!=NULL and tempHead2!=NULL){
                    if(tempHead1->index==tempHead2->index){
                        val+=tempHead1->data*tempHead2->data;
                        tempHead1=tempHead1->next;
                        tempHead2=tempHead2->next;
                    }
                    else if(tempHead1->index<tempHead2->index){
                        tempHead1=tempHead1->next;
                    }
                    else{
                        tempHead2=tempHead2->next;
                    }
                }
                if(val!=0){
                    if(ans[i]==NULL){
                        ans[i]=new Node(val,j);
                        tailsAns[i]=ans[i];
                        

                    }
                    else{
                        
                        insertAtTail(tailsAns[i],j,val);
                    }
                }

            }
        }
        for(int i=0;i<r1;i++){
            cout<<"ROW "<<i<<": ";
            print(ans[i]);
        }      
    }
}