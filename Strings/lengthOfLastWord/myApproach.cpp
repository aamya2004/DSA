class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans = 0;
        int size = s.size();
        int i = 0;
      //  cout<<size;
        for(i = size-1; i>0; i--){
            if(s[i]==' '){
                continue;
            }
            else if(s[i]!=' ' && s[i-1]!=' '){
                ans++;
            }
            else if(s[i]!=' ' && s[i-1] ==' '){
                ans++;
                break;
            }
        }
        if(i==0 && s[i]!=' '){
            ans++;
        }
        if(size==1){
            return 1;
        }
        return ans;

    }
};