class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }

        if(sum%2!=0) return false;
        int halfSum=sum/2;

        vector<vector<int>> dp(n+1,vector<int>(halfSum+1,0));
        
        for(int i=0;i<=n;i++) dp[i][0]=1;

        for(int i=1;i<=n;i++){
            for(int j=1;j<=halfSum;j++){
                int notTake=dp[i-1][j];
                int take=0;

                if(j>=nums[i-1]){
                    take=dp[i-1][j-nums[i-1]];
                }

                dp[i][j]=notTake || take;
            }
        }

        if(dp[n][halfSum]==1) return true;
        return false;
        
    }
};
