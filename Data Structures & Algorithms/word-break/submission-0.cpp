class Solution {
public:
    bool recursion(string &s, int index,vector<string>& wordDict,unordered_map<string,int>& mpp,vector<int>& dp) {
        if (index == s.size()) {
            return true;
        }
        if (dp[index] != -1) {
            return dp[index];
        }
        string str = "";
        for (int i = index; i < s.size(); i++) {
            str += s[i];
            if (mpp[str] && recursion(s, i + 1, wordDict, mpp, dp)) {
                return dp[index] = true;
            }
        }
        return dp[index] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        int index = 0;
        unordered_map<string,int> mpp;

        for (auto word : wordDict) {
            mpp[word] = 1;
        }

        vector<int> dp(s.size(), -1);
        return recursion(s, index, wordDict, mpp, dp);
    }
};
