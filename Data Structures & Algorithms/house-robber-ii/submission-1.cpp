class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);
        vector<int> dp(n,0);

        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);

        for(int index=2;index<n-1;index++){
            dp[index]=max(dp[index-2]+nums[index],dp[index-1]);
        }

        int res1=dp[n-2];

        dp[0]=0;
        dp[1]=nums[1];

        for(int index=2;index<n;index++){
            dp[index]=max(dp[index-2]+nums[index],dp[index-1]);
        }
        
        int res2=dp[n-1];

        return max(res1,res2);
    }
};
