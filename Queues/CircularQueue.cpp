#include <bits/stdc++.h> 
class CircularQueue{
    public:
    int *arr;
    int size;
    int front;
    int rear;
    CircularQueue(int n){
       size = n;
       arr = new int[size];
       front = -1;
       rear = -1;
    }

    // Enqueues 'X' into the queue. Returns true if it gets pushed into the stack, and false otherwise.
    bool enqueue(int data){
        if((front == 0 && rear == size-1) || (rear == (front-1)%(size-1))){
            //queue full
            return false;
        }
        else if(front==-1){
                rear=front=0;
            }
        else if(front!=0 && rear==size-1){
                rear = 0;
            }
        else{
                rear++;
            }
        arr[rear]=data;
        return true;
        }

    

    // Dequeues top element from queue. Returns -1 if the stack is empty, otherwise returns the popped element.
    int dequeue(){
        if(front==-1){
            return -1;
        }
        int ans = arr[front];
        arr[front] = -1;
        if(front == rear){
               // arr[front]=-1;
                front=rear=-1;
                
            }
        else if(front == size-1){
                front = 0;
            }
        else{
                front++;
            }
    
        return ans;
    }
};