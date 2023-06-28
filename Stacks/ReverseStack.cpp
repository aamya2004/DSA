#include <bits/stdc++.h>
using namespace std;
int main()
{
    string a = " Aamya";
    stack<char> st;
    string ans = " ";

    //pushing into the stack
    for (int i = 0; i < a.length(); i++){
        char b = a[i];
        st.push(b);
    }

    //popping out ans inserting in the ans
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    
    //printing the reversed string
    for (int i = 0; i < ans.length(); i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    

    return 0;
}