class Solution {
public:
    int binarySearch(vector<int>& nums, int target,int s, int e){
        int mid = 0;
        while(s<=e){
            mid = s+(e-s)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]>target){
                e = mid-1;
            }
            else{
                s = mid+1;
            }
        }
        if(mid == e){
            return mid+1;
        }
        return mid;
    }
    int searchInsert(vector<int>& nums, int target) {
        int s = 0;
        int e = nums.size()-1;
        int ans = binarySearch(nums,target,s,e);
        return ans;
    }
};