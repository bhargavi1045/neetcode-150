class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        map<int,int> mpp;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
        }

        int maxConsecutive=1;
        int consecutive=1;
        int last=INT_MAX;

        for(auto m : mpp){
            if(last==INT_MAX){
                last=m.first;
            }
            else{
                if(m.first==last+1){
                    consecutive++;
                }
                else{
                    consecutive=1;
                }
                last=m.first;
                maxConsecutive=max(maxConsecutive,consecutive);
            }
        }
        return maxConsecutive;
    }
};
