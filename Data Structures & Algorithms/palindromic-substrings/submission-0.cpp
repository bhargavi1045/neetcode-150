class Solution {
public:
    int countSubstrings(string s) {
        if(s == "") return 0;

        int n = s.size();
        int maxLen = 1;
        int count=0;

        for(int i = 0; i < n; i++) {
            count++;
            if(i + 1 < n && s[i] == s[i+1]) {
                int left = i;
                int right = i + 1;
                int len = 0;

                while(left >= 0 && right < n) {
                    if(s[left] != s[right]) break;

                    count++;
                    left--;
                    right++;
                }
            }
            int left = i - 1;
            int right = i + 1;

            while(left >= 0 && right < n) {
                if(s[left] != s[right]) break;

                count++;
                left--;
                right++;
            }
        }
        return count;
    }
};