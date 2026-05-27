class Solution {
public:
    void recursion(vector<int>&nums,int index,int length,int &maxLength,int last){
        if(index==nums.size()){
            maxLength=max(maxLength,length);
            return;
        }
        recursion(nums,index+1,length,maxLength,last);
        if(nums[index]>last){
            recursion(nums,index+1,length+1,maxLength,nums[index]);
        }
    }
    int lengthOfLIS(vector<int>& nums) {
        int last=-1001;
        int index=0;
        int length=0;
        int maxLength=1;
        recursion(nums,index,length,maxLength,last);
        return maxLength;
    }
};
