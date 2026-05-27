class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>> minHeap;
    int K;
    KthLargest(int k, vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            minHeap.push(nums[i]);
            if(minHeap.size()>k) minHeap.pop();
        }
        K=k;
    }
    
    int add(int val) {
        minHeap.push(val);
        if(minHeap.size()>K) minHeap.pop();
        if(minHeap.empty()) return -1;
        else{
            int kthLargest=minHeap.top();
            return kthLargest;
        }
    }
};
