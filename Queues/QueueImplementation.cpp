#include <bits/stdc++.h> 
class Queue {
public:
    int *arr;
    int size;
    int fronts;
    int rear;
    Queue() {
        size = 100001;
        arr = new int[size];
        fronts = 0;
        rear = 0;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        if(fronts == rear){
            return true;
        }
        return false;
    }

    void enqueue(int data) {
        if(fronts == rear){
            fronts = 0;
            rear = 0;
        }
        if(rear!=size-1){
            arr[rear] = data;
            rear++;
        }
    }

    int dequeue() {
        int temp;
        if(fronts!=rear){
            temp = arr[fronts];
            arr[fronts] = -1;
            fronts++;
            return temp;
        }
        else{
            return -1;
        }
    }

    int front() {
        if(rear == fronts){
            return -1;
        }
        else{
            return arr[fronts];
        }
    }
};