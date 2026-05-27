class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> mpp;

        int left=0;
        int right=0;
        int maxLen=0;
        int maxFreq=0;

        while(right<s.size()){
            mpp[s[right]]++;
            maxFreq=max(maxFreq,mpp[s[right]]);
            
            while((right-left+1)-maxFreq>k){
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
