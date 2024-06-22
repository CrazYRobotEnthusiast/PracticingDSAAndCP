/*You will be given ‘N’ queries. You need to implement ‘N’ queues using an array according to those queries. Each query will belong to one of these two types:

1 ‘X’ N: Enqueue element ‘X’  into the end of the nth queue. Returns true if the element is enqueued, otherwise false.

2 N: Dequeue the element at the front of the nth queue. Returns -1 if the queue is empty, otherwise, returns the dequeued element.*/

#include <bits/stdc++.h> 
class NQueue{
public:
    int *arr;
    int *next;
    int *front;
    int *rear;
    int N;
    int K;
    int freeSpace;
    NQueue(int n, int s){
        N=s;
        K=n;
        arr=new int[N];
        front=new int[K];
        rear=new int[K];
        next=new int[N];
        for(int i=0;i<N-1;i++)next[i]=i+1;
        next[N-1]=-1;
        freeSpace=0;
        for(int i=0;i<K;i++){
            front[i]=-1;
            rear[i]=-1;
        }
    }

    // Enqueues 'M' into the Xth queue. Returns true if it gets pushed into the queue, and false otherwise.
    bool enqueue(int m, int x){
        if(freeSpace!=-1){
            if (front[x - 1] == -1) {
                front[x-1]=freeSpace;
                rear[x-1]=freeSpace;
                arr[freeSpace]=m;
                freeSpace=next[freeSpace];
                next[rear[x-1]]=-1;
            }
            else{
                next[rear[x-1]]=freeSpace;
                arr[freeSpace]=m;
                rear[x-1]=freeSpace;
                freeSpace=next[freeSpace];
                next[rear[x-1]]=-1;
            }
            return true;
        }
        else{
            return false;
        }
    }

    // Dequeues top element from Xth queue. Returns -1 if the queue is empty, otherwise returns the popped element.
    int dequeue(int x){
        if(front[x-1]==-1) return -1;
        else{
            int a=arr[front[x-1]];
            int tempFree=front[x-1];
            front[x-1]=next[front[x-1]];
            int t=freeSpace;
            if(t==-1) freeSpace=tempFree;
            else{
                while(next[t]!=-1) t=next[t];
                next[t]=tempFree;
            }
            next[tempFree]=-1;
            return a;
        }
    }
};