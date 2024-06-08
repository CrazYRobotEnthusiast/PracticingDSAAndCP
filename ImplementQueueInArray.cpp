#include <bits/stdc++.h> 
class Queue {
public:
    int *arr;
    int qfront;
    int rear;
    int size;
    Queue() {
        // Implement the Constructor
        size=5000;
        arr=new int[size];
        rear=0;
        qfront=0;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        if(rear==qfront) return true;
        else return false;
    }

    void enqueue(int data) {
        if(size==rear) return;
        else arr[rear++]=data;
    }

    int dequeue() {
        if(qfront==rear) return -1;
        else{
            int ans=arr[qfront];
            for(int i=0;i<rear-1;i++){
                arr[i]=arr[i+1];
            }
            rear--;
            return ans;
        }
    }

    int front() {
        if(qfront==rear) return -1;
        else return arr[qfront];
    }
};