class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
         vector<int> prefixPro(nums.size());
         vector<int> suffixPro(nums.size());
         vector<int> result(nums.size());
         prefixPro[0]=1;
         suffixPro[nums.size()-1]=1;
         for(int i=0;i<nums.size();i++){
            if(i>0){
               prefixPro[i]=prefixPro[i-1]*nums[i-1];
               suffixPro[nums.size()-i-1]=suffixPro[nums.size()-i]*nums[nums.size()-i];
            }
         }
         
         for(int i=0;i<nums.size();i++){
            result[i]=prefixPro[i]*suffixPro[i];
         }
         return result;
    }
};
