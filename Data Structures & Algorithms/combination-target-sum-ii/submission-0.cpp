class Solution {
public:
    void recursion(int index,vector<int>&candidates,int target,int sum,vector<int>a,vector<vector<int>>&ans){
        if(sum==target){
            ans.push_back(a);
            return;
        }
       
        if(index==candidates.size()) return;

        for(int i=index;i<candidates.size();i++){
            if(i>index && candidates[i]==candidates[i-1]) continue;
            if(candidates[i]>target) return;
            if(sum+candidates[i]<=target){
                a.push_back(candidates[i]);
                recursion(i+1,candidates,target,sum+candidates[i],a,ans);
                a.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int index=0;
        int sum=0;
        vector<int> a;
        vector<vector<int>> ans;
        
        sort(candidates.begin(),candidates.end());
        recursion(index,candidates,target,sum,a,ans);

        return ans;
    }
};
