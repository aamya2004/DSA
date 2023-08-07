#include <bits/stdc++.h> 
/*

    intervals[i][0] = start point of i'th interval
    intervals[i][1] = finish point of i'th interval

*/

vector<vector<int>> mergeIntervals(vector<vector<int>> intervals)
{
            stack<int> st;
         int n = intervals.size();
         sort(intervals.begin(),intervals.end());
         vector<vector<int>> ans;
         vector<int> v1;
         //int el1 = intervals[0];
         //int el2 = intervals[];
         st.push(intervals[0][0]);
         st.push(intervals[0][1]);

         //st.push(el2);
         for(int i = 1 ; i<intervals.size(); i++){
                 if(intervals[i][0] <= st.top()){
                         int num = st.top();
                         st.pop();
                         st.push(max(intervals[i][1], num));
                 }
                 else{
                     while(!st.empty()){
                         v1.push_back(st.top());
                         st.pop();
                     }
                     reverse(v1.begin(),v1.end());
                     ans.push_back(v1);
                     v1.clear();
                     st.push(intervals[i][0]);
                     st.push(intervals[i][1]);
                     
                 }
             
         }
         while(!st.empty())
         {
                        v1.push_back(st.top());
                         st.pop();
         }
                     reverse(v1.begin(),v1.end());
                     ans.push_back(v1);
                     v1.clear();
         return ans;
}
