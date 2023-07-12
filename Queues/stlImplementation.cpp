#include <bits/stdc++.h>
using namespace std;
int main()
{
    queue<int> q;
    q.push(10);
    q.push(20);
    cout << "Front: " << q.front() << endl;
    cout << "Rear: " << q.back() << endl;
    cout << "Size of queue : " << q.size() << endl;
    q.pop();
    cout << "Size of queue : " << q.size() << endl;
    cout << "Front: " << q.front() << endl;

    return 0;
}