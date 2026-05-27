class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,0);

        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);

        for(int index=2;index<n;index++){
            dp[index]=max(dp[index-2]+nums[index],dp[index-1]);
        }

        return dp[n-1];
    }
};
