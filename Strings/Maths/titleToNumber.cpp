    int titleToNumber(string columnTitle) {
        int ans = 0;
        for(int i = 0; i<columnTitle.size(); i++){
            char express = columnTitle[i];
            int d = express - 'A' + 1;
            ans = ans*26 + d;
        }
        return ans;
    }