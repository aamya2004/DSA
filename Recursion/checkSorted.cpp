#include <bits/stdc++.h>
using namespace std;
//check whether array sorted or not
bool checkSorted(int arr[], int size){
    if(size==0||size==1){
        return true;
    }
    else if(arr[0]>arr[1]){
        return false;
    }
    else{
        bool ans = checkSorted(arr+1,size-1);
        return ans;
    }
}
int main(){
    //static input example
    int arr[]={2,4,6,8,10};
    int arr2[]={2,3,4,1,0};
    int n=sizeof(arr)/sizeof(arr[0]);
    int n1=sizeof(arr2)/sizeof(arr[0]);
    cout<<checkSorted(arr,n)<<endl;
    cout<<checkSorted(arr2,n1)<<endl;
}
