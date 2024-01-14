class Solution {
public:
    int minSteps(string s, string t) {
        int ans=0;
        vector<int> v1(26,0);
        vector<int> v2(26,0);
        for(auto i : s){
            int index = i - 'a';
            v1[index]++;
        }
        for(auto i : t){
            int index = i - 'a';
            v2[index]++;
        }
        for(int i = 0 ; i<26; i++){
            if(v1[i]>v2[i]){
                int diff = v1[i]-v2[i];
                ans+=diff;
            }
        }
        return ans;
    }
};