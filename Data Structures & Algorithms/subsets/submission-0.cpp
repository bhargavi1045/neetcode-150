class Solution {
public:
    void find(vector<int>&nums,int index,vector<int>a,vector<vector<int>>&ans){
        if(index==nums.size()){
            ans.push_back(a);
            return;
        }
        a.push_back(nums[index]);
        find(nums,index+1,a,ans);
        a.pop_back();
        find(nums,index+1,a,ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int index=0;
        vector<vector<int>> ans;
        vector<int> a;
        
        find(nums,index,a,ans);
        return ans;
    }
};
