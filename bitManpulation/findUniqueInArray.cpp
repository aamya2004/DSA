    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(int x : nums){
            ans^=x; //XOR of elements returns true only if both different
        }
        return ans;
    }