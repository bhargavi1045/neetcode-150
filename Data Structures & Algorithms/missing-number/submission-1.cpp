class Solution {
public:
    int missingNumber(vector<int>& nums) {
       int xOR=0;

       for(int i=0;i<nums.size()+1;i++) xOR^=i;
       for(int i=0;i<nums.size();i++){
        xOR^=nums[i];
       }

       return xOR;
    }
};
