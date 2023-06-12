#include <bits/stdc++.h>
using namespace std;
void insertionSort(int* arr,int size){
    if(size==0||size==1){
        return;
    }
    insertionSort(arr,size-1);
    int temp=arr[size-1];
    int j=size-2;
    while(j>=0 && arr[j]>temp){
        arr[j+1]=arr[j];
        j--;
    }
    arr[j+1]=temp;
}
int main(){
    int arr[5]={2,1,3,4,0};
    int n= sizeof(arr)/sizeof(arr[0]);
    insertionSort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
