    int missingNumber(vector<int>& nums) {
        int ans;
        int n = nums.size();
        int totalSum = n*(n+1)/2; //sum of n numbers
        int sum = 0;
        for(int i = 0; i<nums.size(); i++){
            sum+=nums[i];
        }
        ans = totalSum - sum;
        return ans;
    }