#include <bits/stdc++.h>
using namespace std;

class Stack{
    public:
    int *arr;
    int size;
    int top;

    Stack(int size){
        this->size = size; //uss stack ka size dediya
        arr = new int[size]; //naya array bnadiya
        top = -1;
    }

    
    bool isEmpty(){
        if(top == -1){
            return true;
        }
        else{
            return false;
        }
    }

    void push(int element){
        if(size-top > 1){
            top++;
            arr[top] = element;
        }
        else{
            cout<<"Stack Overflow"<<endl;
        }
    }

    void pop(){
        if(top == -1){
            cout<<"Stack Underflow"<<endl;
        }
        else{
            top--;
        }
    }

    void peek(){
        if(top == -1){
            cout<<"No element"<<endl;
        }
        else{
            cout<<"The top element of stack is: "<< arr[top] <<endl;
        }
    }


    
};

int main()
{
    Stack obj1(5);
    obj1.push(2);
    obj1.push(3);
    obj1.push(4);
    obj1.push(5);
    obj1.push(6);
    obj1.pop();
    obj1.peek();
    bool check = obj1.isEmpty();
    cout<<check<<endl;
    return 0;
}