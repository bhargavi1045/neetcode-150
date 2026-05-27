class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mpp;

        int left=0;
        int right=0;
        int maxLen=0;

        while(right<s.size()){
            mpp[s[right]]++;
            while(right-left+1>mpp.size()){
                mpp[s[left]]--;
                if(mpp[s[left]]==0) mpp.erase(s[left]);
                left++;
            }
            maxLen=max(maxLen,right-left+1);
            right++;
        }

        return maxLen;
    }
};
