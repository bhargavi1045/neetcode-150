class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<int>> mpp;
        for(int i=0;i<strs.size();i++){
            string s=strs[i];
            sort(s.begin(),s.end());
            if(mpp.find(s)==mpp.end()){
                mpp[s].push_back(i);
            }
            else mpp[s].push_back(i);
        }

        vector<vector<string>> st;
        for(auto m : mpp){
            vector<string> s;
            for(int i=0;i<m.second.size();i++){
                s.push_back(strs[m.second[i]]);
            }
            st.push_back(s);
        }
        return st;
    }
};
