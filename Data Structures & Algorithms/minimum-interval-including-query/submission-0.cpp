class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        sort(intervals.begin(), intervals.end());

        int m = queries.size();
        vector<pair<int,int>> sortedQ(m);
        for (int i = 0; i < m; i++) sortedQ[i] = {queries[i], i};
        sort(sortedQ.begin(), sortedQ.end());

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minHeap;

        vector<int> ans(m);
        int i = 0; 

        for (auto [value, origIdx] : sortedQ) {
            while (i < intervals.size() && intervals[i][0] <= value) {
                int start  = intervals[i][0];
                int end    = intervals[i][1];
                int length = end - start + 1;
                minHeap.push({length, end});
                i++;
            }
            while (!minHeap.empty() && minHeap.top().second < value) {
                minHeap.pop();
            }

            ans[origIdx] = minHeap.empty() ? -1 : minHeap.top().first;
        }

        return ans;
    }
};