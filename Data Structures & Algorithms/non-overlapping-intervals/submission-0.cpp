class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.size()<=1) return 0;

        sort(intervals.begin(),intervals.end(),[](const vector<int> &a,const vector<int>&b){
            return a[1]<b[1];
        });

        int last=intervals[0][1];
        int toBeRemoved=0;
        
        for(int i=1;i<intervals.size();i++){
            if(last>intervals[i][0]){
                toBeRemoved++;
            }
            else last=intervals[i][1];
        }
        return toBeRemoved;
    }
};
