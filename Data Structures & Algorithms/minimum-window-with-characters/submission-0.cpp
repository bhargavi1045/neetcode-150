class Solution {
public:
    string minWindow(string s, string t) {
        int left=0;
        int right=0;
        int n=s.size();
        int minLength=INT_MAX;
        int startInd=-1;

        unordered_map<char,int> mpp;

        for(int i=0;i<t.size();i++){
            mpp[t[i]]++;
        }

        int count=0;
        while(right<n){
            if(mpp[s[right]]>0) count++;
            mpp[s[right]]--;

            while(count==t.size()){
                if(right-left+1<minLength){
                    minLength=right-left+1;
                    startInd=left;
                }
                mpp[s[left]]++;
                if(mpp[s[left]]>0) count--;
                left++;
            }

            right++;
        }
        if(startInd==-1) return "";
        else return s.substr(startInd,minLength);
    }
};
