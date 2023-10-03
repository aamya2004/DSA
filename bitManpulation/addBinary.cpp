class Solution {
public:
    string addBinary(string a, string b) {
        string ans = "";
        int i = 0;
        int size_a = a.length();
        int size_b = b.length();
        int carry = 0;
        
        while(i<size_a || i<size_b || carry!=0){
            
            int x = 0;
            if(i<size_a && a[size_a-i-1]=='1'){
                x=1;
            }
            
            int y = 0;
            if(i<size_b && b[size_b-i-1] == '1'){
                y=1;
            }
            ans = to_string((x+y+carry)%2)+ans;
            carry = (x+y+carry)/2;
            i+=1;
        }
        return ans;
    }
};