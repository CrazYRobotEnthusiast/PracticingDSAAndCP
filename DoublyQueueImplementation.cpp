#include <bits/stdc++.h> 
class Deque
{
public:
    int *arr;
    int front;
    int rear;
    int size;
    bool isfull;
    Deque(int n)
    {
        isfull=false;
        if(n==0) isfull=true;
        size=n;
        arr=new int[size];
        rear=0;
        front=0;
    }

    // Pushes 'X' in the front of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushFront(int x)
    {
        if(isfull) return false;
        front--;
        if(front==-1) front =size-1;
        if(front==rear) isfull=true;
        arr[front]=x;
        return true;
    }

    // Pushes 'X' in the back of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushRear(int x)
    {
        if(isfull) return false;
        arr[rear]=x;
        rear++;
        if(rear==size) rear=0;
        if(rear==front) isfull=true;
        return true;
        // Write your code here.
    }

    // Pops an element from the front of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popFront()
    {
        if(!isfull and front==rear) return -1;
        int ans=arr[front];
        if(isfull) isfull=false;
        front++;
        if(front==size) front=0;
        return ans;
        // Write your code here.
    }

    // Pops an element from the back of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popRear()
    {   
        if(!isfull and front==rear) return -1;
        --rear;
        if(rear==-1) rear=size-1;
        int ans=arr[rear];
        if(isfull) isfull=false;
        return ans;
        // Write your code here.
    }

    // Returns the first element of the deque. If the deque is empty, it returns -1.
    int getFront()
    {
        if(!isfull and front==rear) return -1;
        return arr[front];
        // Write your code here.
    }

    // Returns the last element of the deque. If the deque is empty, it returns -1.
    int getRear()
    {
        if(!isfull and front==rear) return -1;
        if(rear-1==-1) return arr[size-1];
        return arr[rear-1];
        // Write your code here.
    }

    // Returns true if the deque is empty. Otherwise returns false.
    bool isEmpty()
    {
        if(!isfull and front==rear) return true;
        return false;
        // Write your code here.
    }

    // Returns true if the deque is full. Otherwise returns false.
    bool isFull()
    {
        if(isfull) return true;
        return false;
        // Write your code here.
    }
};