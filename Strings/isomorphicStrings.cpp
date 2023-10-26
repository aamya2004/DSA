    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> mp_st;
        unordered_map<char,char> mp_ts;
        if(s.length()!=t.length()){
            return false;
        }
        for(int i = 0; i<s.length() ; i++){
            if(mp_st.find(s[i])== mp_st.end() && mp_ts.find(t[i]) == mp_ts.end()){
                //mtlb i vala element nahi mila abhi tou add krna pdega map me
                mp_st[s[i]] = t[i];
                mp_ts[t[i]] = s[i];
            }
            else{
                //mtlb element milgya hai already
                if(mp_st[s[i]]!=t[i] || mp_ts[t[i]]!=s[i]){
                    return false;
                }
            }
        }
        return true;


    }