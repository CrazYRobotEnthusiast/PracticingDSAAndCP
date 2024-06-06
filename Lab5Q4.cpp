#include<iostream>
using namespace std;
class Node{
    public:
    int d;
    Node *next;
    Node (int d){
        this->d=d;
        this->next=NULL;
    }
};
void insertAtTail(Node *&head,int d){
    if(head==NULL){
        head=new Node(d);
        return;
    }
    Node *temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    Node *a=new Node(d);
    temp->next=a;
}
void Heapify(Node *q[],int &size,int i){
    int smallest=i;
    int left=2*i;
    int right=2*i+1;
    int k=left;
    if(left<=size and right<=size){
        if(q[left]->d>q[right]->d) k=right;
    }
    if(k<=size and q[k]->d<q[smallest]->d){
        smallest=k;
        swap(q[smallest],q[i]);
    }
    if(smallest!=i) Heapify(q,size,smallest);
    return;
}
void buildHeap(Node *q[],int &size){
    for(int i=size/2;i>0;i--){
        Heapify(q,size,i);
    }
    return;
}
int extractMin(Node *q[],int &size){
    if(size==1){
        int min=q[1]->d;
        q[1]=q[1]->next;
        if(q[1]==NULL) size--;
        return min;
    }
    else{
        int min=q[1]->d;
        q[1]=q[1]->next;
        if(q[1]==NULL){
            q[1]=q[size];
            size--;
        }
        Heapify(q,size,1);
        return min;
    }
}
void merging(Node *q[],int &size,int mainArray[]){
    buildHeap(q,size);
    int i=0;
    while(size!=0){
        mainArray[i]=extractMin(q,size);
        i++;
    }
}
int main(){
    int k;
    cout<<"Enter number of lists: ";
    cin>>k;
    Node *q[k+1];
    q[0]=NULL;
    int c=0;
    for(int i=1;i<=k;i++){
        cout<<"Enter list: ";
        int a;
        cin>>a;
        Node *t=NULL;
        while(a!=-1){
            insertAtTail(t,a);
            cin>>a;
            c++;
        }
        q[i]=t;
    }
    int mainArray[c];
    int size=k;
    merging(q,size,mainArray);
    for(int i=0;i<c;i++) cout<<mainArray[i]<<" ";

}