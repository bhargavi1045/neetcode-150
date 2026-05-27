class Solution {
public:
    void recursion(int index,vector<int>&nums,int target,int sum,vector<int> a,vector<vector<int>>&ans){
        if(sum==target){
            ans.push_back(a);
            return;
        }
        if(index==nums.size()) return;
        recursion(index+1,nums,target,sum,a,ans);
        if(nums[index]+sum<=target){
            a.push_back(nums[index]);
            recursion(index,nums,target,sum+nums[index],a,ans);
        }
       
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> a;
        int sum=0;
        int index=0;

        recursion(index,nums,target,sum,a,ans);

        return ans;
    }
};
