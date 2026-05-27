class Solution {
public:
    void recursion(vector<int>&nums,set<vector<int>>&s,int index,vector<int>v){
        if(index==nums.size()){
            sort(v.begin(),v.end());
            s.insert(v);
            return;
        }
        recursion(nums,s,index+1,v);
        v.push_back(nums[index]);
        recursion(nums,s,index+1,v);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        set<vector<int>> s;
        vector<int> v;
        recursion(nums,s,0,v);
        
        for(auto ele : s){
            ans.push_back(ele);
        }

        return ans;
    }
};