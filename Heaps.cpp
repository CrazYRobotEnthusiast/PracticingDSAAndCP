#include<iostream>
using namespace std;
class Heap{
    public:
    int arr[100];
    int size=0;
    Heap(){
        this->size=0;
        this->arr[0]=-1;
    }
    void insert(int d){
        size=size+1;
        int index=size;
        arr[index]=d;
        while(index>1){
            int parent=index/2;
            if(arr[parent]<arr[index]){
                swap(arr[index],arr[parent]);
                index=parent;
            }
            else return;
        }
        return;
    }
    void print(){
        for(int i=1;i<=size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    void extractMax(){
        if(size==0){
            cout<<"Nothing to delete.";
            return;
        }
        arr[1]=arr[size];
        size--;

        //Taking root node to correct position
        int i=1;
        while(i<size){
            int leftIndex=2*i;
            int rightIndex=2*i+1;
            int k=leftIndex;
            if(leftIndex<=size and rightIndex<=size){
                if(arr[rightIndex]>arr[leftIndex]) k=rightIndex;

            }
            if(k<=size and arr[i]<arr[k]){
                swap(arr[i],arr[k]);
                i=k;
            }
            else return;
        }
        return;
    }
};
void heapify(int arr[],int n,int i){
    int largest=i;
    int left=2*i;
    int right=2*i+1;
    if(left<=n and arr[left]>arr[largest]){
        largest=left;
    }
    if(right<=n and arr[right]>arr[largest]){
        largest=right;
    }
    if(largest!=i){
        swap(arr[largest],arr[i]);
        heapify(arr,n,largest);
    }
}
void Heapifying(int arr[],int size){

    for(int i=size/2;i>0;i--){
        heapify(arr,size,i);
    }
}
void HeapSort(int arr[],int size){
    int n=size;
    while(size>1){
        swap(arr[1],arr[size]);
        size--;
        heapify(arr,size,1);
    }
    for(int i=1;i<=n;i++) cout<<arr[i]<<" ";
    cout<<endl;
}

int main(){
    Heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.print();
    h.extractMax();
    h.print();
    int a[]={-1,70,60,56,45,50};

    int n=5;
    Heapifying(a,n);
    HeapSort(a,n);
    for (int i=1;i<=n;i++){
        cout<<a[i]<<" ";
    }

}