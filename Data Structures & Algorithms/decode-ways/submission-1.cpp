class Solution {
public:
    void recursion(string s,int index,int &ans){
        if(index>=s.size()){
            ans+=1;
            return;
        }
        if(s[index]=='0') return;
        recursion(s,index+1,ans);
        
        if(s[index]<='2' && index+1<s.size()){
            if(s[index]=='1' || s[index]=='2' && s[index+1]<='6') recursion(s,index+2,ans);
        }
    }
    int numDecodings(string s) {
        // int ans=0;
        // recursion(s,0,ans);
        // return ans;

        if(s[0]=='0') return 0;
        int n=s.size();
        vector<int> dp(n+1,0);
        dp[0]=1;
        dp[1]=(s[0]=='0')?0:1;

        for(int i=2;i<=n;i++){
            if(s[i-1]!='0'){
                dp[i]+=dp[i-1];
            }
            if(s[i-2]<='2'){
               if(s[i-2]=='1' || s[i-2]=='2' && s[i-1]<='6') dp[i]+=dp[i-2];
            }
        }

        return dp[n];
    }
};
