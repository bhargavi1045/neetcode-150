class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        vector<int> visited(nums.size()-1,0);

        for(int i=0;i<nums.size();i++){
            int index=nums[i]-1;
            if(visited[index]==-1) return nums[i];
            else visited[index]=-1;
        }

        return -1;
    }
};
