class Solution {
public:
    void generatePermutations(vector<int>&nums,int index,vector<int>a,vector<vector<int>>&ans){
        if(index==nums.size()){
            ans.push_back(a);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=-11){
                int value=nums[i];
                a.push_back(value);
                nums[i]=-11;
                generatePermutations(nums,index+1,a,ans);
                a.pop_back();
                nums[i]=value;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> a;
        int index=0;

        generatePermutations(nums,index,a,ans);

        return ans;
    }
};
