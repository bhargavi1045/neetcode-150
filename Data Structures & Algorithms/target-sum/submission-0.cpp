class Solution {
public:
    void recursion(vector<int>&nums,int target,int index,long long sum,int &ans){
        if(index==nums.size()){
            if(sum==target) ans+=1;
            return;
        }
        if(sum+nums[index]<=INT_MAX){
            recursion(nums,target,index+1,sum+nums[index],ans);
        } 
        if(sum-nums[index]>=INT_MIN){
            recursion(nums,target,index+1,sum-nums[index],ans);
        }
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int ans=0;
        int index=0;
        long long sum=0;

        recursion(nums,target,index,sum,ans);
        return ans;
    }
};
