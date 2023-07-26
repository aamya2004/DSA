#include <bits/stdc++.h> 
vector<pair<char,int>> duplicate_char(string s, int n){
    vector<pair<char,int>> ans;
    int arr[256] = {0};
    for(int i=0;i<s.length();i++){
        arr[int(s[i])]++;
    }
    for(int i=0;i<256;i++){
        if(arr[i]>1){
            ans.push_back({char(i),arr[i]});
        }
    }
    return ans;
}
