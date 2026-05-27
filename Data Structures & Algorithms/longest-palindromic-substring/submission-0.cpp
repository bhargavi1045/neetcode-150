class Solution {
public:
    string longestPalindrome(string s) {
        if(s == "") return "";

        int n = s.size();
        int maxLen = 1;
        string res = s.substr(0,1);

        for(int i = 0; i < n; i++) {
            if(i + 1 < n && s[i] == s[i+1]) {
                int left = i;
                int right = i + 1;
                int len = 0;

                while(left >= 0 && right < n) {
                    if(s[left] != s[right]) break;

                    len += 2;
                    if(len > maxLen) {
                        maxLen = len;
                        res = s.substr(left, right - left + 1);
                    }
                    left--;
                    right++;
                }
            }
            int left = i - 1;
            int right = i + 1;
            int len = 1;

            while(left >= 0 && right < n) {
                if(s[left] != s[right]) break;

                len += 2;
                if(len > maxLen) {
                    maxLen = len;
                    res = s.substr(left, right - left + 1);
                }
                left--;
                right++;
            }
        }

        return res;
    }
};