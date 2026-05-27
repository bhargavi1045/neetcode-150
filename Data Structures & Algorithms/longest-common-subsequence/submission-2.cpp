class Solution {
public:
    void recursion(string text1,string text2,int index1,int index2,int len,int &maxLen){
        if(index1==text1.size() || index2==text2.size()){
           maxLen=max(maxLen,len);
           return;
        }
        if(text1[index1]==text2[index2]){
            recursion(text1,text2,index1+1,index2+1,len+1,maxLen);
        }
        else{
            recursion(text1,text2,index1+1,index2,len,maxLen);
            recursion(text1,text2,index1,index2+1,len,maxLen);
            recursion(text1,text2,index1+1,index2+1,len,maxLen);
        }
    }
    int tabulation(string text1,string text2){
        int n1=text1.size();
        int n2=text2.size();

        vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));

        for(int index1=1;index1<=n1;index1++){
            for(int index2=1;index2<=n2;index2++){
                if(text1[index1-1]==text2[index2-1]){
                    dp[index1][index2]=dp[index1-1][index2-1]+1;
                }
                else{
                    dp[index1][index2]=max({dp[index1-1][index2],dp[index1-1][index2-1],dp[index1][index2-1]});
                }
            }
        }

        return dp[n1][n2];
    }
    int longestCommonSubsequence(string text1, string text2) {
        return tabulation(text1,text2);
    }
};
