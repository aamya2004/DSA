//BubbleSort using recursion
#include<bits/stdc++.h>
using namespace std;
void bubbleSort(int *arr,int size){
    if(size==0||size==1){
        return ;
    }
    for(int i=0;i<size;i++){
      if(arr[i]>arr[i+1]){
          swap(arr[i],arr[i+1]);
      }  
    }
    bubbleSort(arr,size-1);
    
}
int main(){
    //static input
    int arr[5]={2,1,5,4};
    int n=sizeof(arr)/sizeof(arr[0]);
    bubbleSort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
