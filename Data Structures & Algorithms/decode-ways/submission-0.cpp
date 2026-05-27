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
        int ans=0;
        recursion(s,0,ans);
        return ans;
    }
};
