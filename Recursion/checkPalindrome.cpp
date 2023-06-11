//Check for palindrome using recursion
#include<bits/stdc++.h>
using namespace std;
bool checkPalindrome(string& a,int size,int start,int end){
    if(start>end){
        return true;
    }
    if(a[start]!=a[end]){
        return false;
    }
    else{
        start++;
        end--;
        return checkPalindrome(a,size,start,end);
    }
}
int main(){
    //static input
    string a="abcde";
    cout<<a<<endl;
    string b="abcba";
    cout<<b<<endl;
    int n=a.length();
    int s=0;
    int e=n-1;
    cout<<checkPalindrome(a,n,s,e)<<endl;
    cout<<checkPalindrome(b,n,s,e)<<endl;
}
