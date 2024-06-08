#include <bits/stdc++.h> 
class CircularQueue{
    public:
        int *arr;
        int front;
        int rear;
        bool isFull;
        int size;
    CircularQueue(int n){
        isFull=false;
        if(n==0) isFull=true;
        arr= new int[n];
        front =0;
        rear=0;
        size=n;
    }

    // Enqueues 'X' into the queue. Returns true if it gets pushed into the stack, and false otherwise.
    bool enqueue(int value){
        if(isFull) return false;
        arr[rear++]=value;
        if(rear==size) rear=0;
        if(front==rear) isFull=true;
        return true;
    }

    // Dequeues top element from queue. Returns -1 if the stack is empty, otherwise returns the popped element.
    int dequeue(){
        if(!isFull and rear==front) return -1;
        int ans=arr[front];
        front++;
        if(front==size) front=0;
        if(isFull) isFull=false;
        return ans;
    }
};