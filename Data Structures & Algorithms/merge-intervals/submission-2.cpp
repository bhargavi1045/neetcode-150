class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size()<1) return {};
        else if(intervals.size()==1) return intervals;

        vector<vector<int>> merged;

        sort(intervals.begin(),intervals.end());
        merged.push_back(intervals[0]);

        for(int i=1;i<intervals.size();i++){
            if(merged.empty() || merged.back()[1]<intervals[i][0]){
                merged.push_back(intervals[i]);
            }
            else{
                merged.back()[1]=max(intervals[i][1],merged.back()[1]);
            }
        }

        return merged;
    }
};
