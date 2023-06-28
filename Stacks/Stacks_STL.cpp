#include <bits/stdc++.h>
using namespace std;
int main()
{
    //creating a stack
    stack<int> a;

    //pushing an element
    a.push(2);
    a.push(3);

    //popping an element
    a.pop();

    //getting top element
    cout<<"Top Element "<<a.top()<<endl;

    //checking stack empty or not
    if(a.empty()){
        cout<<"Stack is empty"<<endl;
    }
    else{
        cout<<"Stack is empty"<<endl;
    }

    cout<<"Size of stack is "<<a.size()<<endl;
    return 0;
}