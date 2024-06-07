#include <bits/stdc++.h> 
class NStack
{
public:
    int *top;
    int *next;
    int *arr;
    int freeSpot;
    int n,s;
    NStack(int N, int S)
    {
        this->top=new int[N];
        this->next=new int[S];
        this->arr=new int[S];
        this->n=S;
        this->s=N;
        this->freeSpot=0;
        for(int i=0;i<S-1;i++) next[i]=i+1;
        next[S-1]=-1;
        for(int i=0;i<N;i++) top[i]=-1;
        
    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {
        if(freeSpot==-1) return false;
        int index=freeSpot;
        freeSpot=next[freeSpot];

        arr[index]=x;
        next[index]=top[m-1];
        top[m-1]=index;
        return true;        
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {
        if(top[m-1]==-1) return -1;
        int pop=arr[top[m-1]];
        int f=freeSpot;
        while(next[f]!=-1)f=next[f];
        next[f]=top[m-1];
        int i=top[m-1];
        top[m-1]=next[top[m-1]];
        next[i]=-1;
        return pop;
    }
};