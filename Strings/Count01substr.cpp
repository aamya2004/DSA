    int maxSubStr(string str){
        int cnt0 = 0;
        int cnt1 = 0;
        
        for(int i = 0; i<str.size(); i++){
            if(str[i]=='0'){
                cnt0++;
            }
            else{
                cnt1++;
            }
        }
        if(cnt0!=cnt1){
            return -1;
        }
        else{
            int ans = 0;
            int i = 0;
            while(i<str.size()){
                if(str[i]=='0' && i<str.size()){
                    cnt0--;
                }
                else{
                    cnt1--;
                }
                if(cnt0==cnt1){
                    ans++;
                }
                i++;
            }
            if(cnt0==0 && cnt1==0){
                return ans;
            }
            return -1;
        }
    }