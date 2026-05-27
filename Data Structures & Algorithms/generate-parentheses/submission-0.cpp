class Solution {
public:
    void generate(int index,int open, int close,int n,string a,vector<string>&ans){
        if(index==2*n){
            ans.push_back(a);
            return;
        }
        if(open<n){
            generate(index+1,open+1,close,n,a+'(',ans);
        }
        if(open>close){
            generate(index+1,open,close+1,n,a+')',ans);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        generate(0,0,0,n,"",res);
        return res;
    }
};
