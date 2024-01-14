class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int> v1(26,0);
        vector<int> v2(26,0);

        for(auto i : word1){
            int index = i - 'a';
            v1[index]++;
        }

        for(auto i : word2){
            int index = i - 'a';
            v2[index]++;
        }

        for(int i = 0 ; i<26 ; i++){
            if(v1[i]==0 && v2[i]!=0){
                return false;
            }
        }
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        for(int i = 0; i<26;i++){
            if(v1[i]!=v2[i]){
                return false;
            }
        }
        return true;
    }
};