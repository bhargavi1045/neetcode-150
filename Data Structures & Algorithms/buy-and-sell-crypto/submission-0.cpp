class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit=0;
        int minimumValue=INT_MAX;
        for(int i=0;i<prices.size();i++){
            if(prices[i]<minimumValue){
                minimumValue=prices[i];
            }
            maxProfit=max(maxProfit,prices[i]-minimumValue);
        }
        return maxProfit;
    }
};
