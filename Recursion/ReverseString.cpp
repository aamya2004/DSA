//Reverse String using recursion
#include<bits/stdc++.h>
using namespace std;
void reverse(string& a,int size,int start,int end){
    if(start>end){
        return;
    }
    swap(a[start],a[end]);
    start++;
    end--;
    reverse(a,size,start,end);
}
int main(){
    //static input
    string a="abcde";
    cout<<a<<endl;
    int n=a.length();
    int s=0;
    int e=n-1;
    reverse(a,n,s,e);
    cout<<a<<endl;
}
