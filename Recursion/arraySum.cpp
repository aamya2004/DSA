#include <bits/stdc++.h>
using namespace std;
//sum of array
int findSum(int arr[], int size){
    if(size==0){
        return 0;
    }
    if(size==1){
        return arr[0];
    }
    int ans = arr[0] + findSum(arr+1,size-1);
    return ans;
}
int main(){
    //static input example
    int arr[]={2,4,6,8,10};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<findSum(arr,n)<<endl;
}
