class Solution {
public:
    void recursion(vector<int>&nums,int index,int length,int &maxLength,int lastIndex){
        if(index==nums.size()){
            maxLength=max(maxLength,length);
            return;
        }
        recursion(nums,index+1,length,maxLength,lastIndex);
        if(nums[index]>nums[lastIndex] || lastIndex==-1){
            recursion(nums,index+1,length+1,maxLength,index);
        }
    }

    
    int lengthOfLIS(vector<int>& nums) {
        int lastIndex=-1;
        int index=0;
        int length=0;
        int maxLength=1;
        recursion(nums,index,length,maxLength,lastIndex);
        return maxLength;
    }
};
