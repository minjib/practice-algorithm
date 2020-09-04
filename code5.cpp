class Solution {
public:
    string longestPalindrome(string s) {
        string ans = s.substr(0, 1);
        int n = s.length();
       
        if(n <= 1) return s;
        string newStr = "";
        
        for(int i=0; i < n; i++) {
            newStr += s.substr(i,1);
            newStr += "#";
        }
        
        int m = newStr.length();
        
        for(int j=2, i = 0, l = 0; j < m - 1; j++) {
            bool evenPal = false;
            bool oddPal = false;
            
            if(i >= 0 && newStr[i] == newStr[j]) {
                if(ans.length() < j - i + 1)
                    ans = newStr.substr(i, j - i + 1);
                i--;
            }
            else {
                i = j - 2;
                if(i >= 0 && newStr[i] == newStr[j]) {
                    if(ans.length() < j - i + 1)
                        ans = newStr.substr(i, j - i + 1);
                    i--;
                }
                else 
                    i = j - 1;
            }
        }
       
        string ret = "";
        
        for(int i=0;i<ans.length();i++){
            if(ans[i] != '#')
                ret += ans.substr(i, 1);
        }
        
        return ans;
    }
};
