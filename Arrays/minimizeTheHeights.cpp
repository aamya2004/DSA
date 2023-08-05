#include <bits/stdc++.h> 
int minimizeIt(vector<int> arr, int k)
{   
		int n = arr.size();
        sort(arr.begin(),arr.end());
        int diff = arr[n-1] - arr[0];
        int mini =0;
        int maxi =0;
        for(int i =0 ; i<n;i++){
            if(arr[i]-k<0){
                continue;
            }
            maxi = max(arr[n-1]-k,arr[i-1]+k);
            mini = min(arr[0]+k,arr[i]-k);
            diff=min(diff,(maxi-mini));
        }

        return diff;
    }
