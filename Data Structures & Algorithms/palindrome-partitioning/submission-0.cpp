class Solution {
public:
    bool isPalindrome(string s){
        int i=0;
        int j=s.size()-1;

        while(i<j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    void solve(string s,int index,vector<string>ap,vector<vector<string>>&ans){
        if(index==s.size()){
            ans.push_back(ap);
            return;
        }
        
        string a="";
        for(int i=index;i<s.size();i++){
            a+=s[i];
            if(isPalindrome(a)){
                ap.push_back(a);
                solve(s,i+1,ap,ans);
                ap.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> ap;
        vector<vector<string>> ans;
        solve(s,0,ap,ans);
        return ans;
    }
};
