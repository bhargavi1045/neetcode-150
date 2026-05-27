class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minHeap;
        for(auto m : mpp){
            minHeap.push({m.second,m.first});
            if(minHeap.size()>k) minHeap.pop();
        }

        vector<int> res;
        while(!minHeap.empty()){
            res.push_back(minHeap.top().second);
            minHeap.pop();
        }

        return res;
    }
};
