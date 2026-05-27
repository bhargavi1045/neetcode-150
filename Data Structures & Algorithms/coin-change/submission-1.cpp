class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        const int INF = 1e9; 
        vector<int> dp(amount + 1, INF);
        dp[0] = 0;

        for(int coin : coins){
            for(int i=coin;i<=amount;i++){
                dp[i]=min(dp[i],dp[i-coin]+1);
            }
        }

        if(dp[amount]==INF) return -1;
        else return dp[amount];
    }
};
