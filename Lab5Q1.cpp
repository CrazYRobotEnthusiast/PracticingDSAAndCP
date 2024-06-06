#include<iostream>
using namespace std;
void Heapify(int arr[],int size,int i){
     int leftChild=2*i;
     int rightChild=2*i+1;
     int largest=i;
     int k=leftChild;
     if(leftChild<=size and rightChild<=size){
        if(arr[leftChild]<arr[rightChild]) k=rightChild;
     }     
     if(arr[k]>arr[largest] and k<size){
        largest=k;
        swap(arr[largest],arr[i]);
     }
     if(largest!=i) Heapify(arr,size,largest);
     return;
}
class Heap{
    public:
    int size;
    int arr[100];
    Heap(){
        size=0;
        arr[size]=-1;
    }
    void extractMax(){
        if(size==0) cout<<"No element to extract";
        else{
            cout<<"Taking out the maximum element "<<arr[1];
            arr[1]=arr[size];
            size--;
            Heapify(this->arr,this->size,1);
        }
    }
    void insert(int d){
        size++;
        arr[size]=d;
    }
};
void buildHeap(int arr[],int size){
    for(int i=size/2;i>0;i--){
        Heapify(arr,size,i);
    }
}
int main(){
    int a[]={-1,34,222,50,36,74,90,31};
    int n=7;
    buildHeap(a,7);
    for(int i=1;i<=7;i++) cout<<a[i]<<" ";
    cout<<endl;
    Heap h;
    for(int i=1;i<=7;i++) h.insert(a[i]);
    h.extractMax();
    cout<<endl;
    for (int i=1;i<=6;i++) cout<<h.arr[i]<<" ";   
}