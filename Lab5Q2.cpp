#include<iostream>
using namespace std;
class Heap{
    public:
    int arr[100];
    int size;
    Heap(){
        size=0;
        arr[size]=-1;
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
    void increase(int i){
        arr[i]+=20;
        i=i/2;
        while(i>0){
            this->heapify(i);
            i=i/2;
        }
    }
    void heapify(int i){
        int largest=i;
        int leftIndex=2*i;
        int rightIndex=2*i+1;
        if(leftIndex<=size and arr[leftIndex]>arr[largest]){
            largest=leftIndex;
            swap(arr[largest],arr[i]);
        }
        if(rightIndex<=size and arr[rightIndex]>arr[largest]){
            largest=rightIndex;
            swap(arr[largest],arr[i]);
        }
        if(largest!=i) heapify(largest);
        return;
    }
        void print(){
        for(int i=1;i<=size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};
int main(){
    Heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.insert(60);
    h.insert(25);
    h.insert(35);
    h.print();
    h.increase(4);
    h.print();
}