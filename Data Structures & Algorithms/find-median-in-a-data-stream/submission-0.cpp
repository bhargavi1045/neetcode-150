class MedianFinder {
public:
    priority_queue<int> maxHeap;
    priority_queue<int,vector<int>,greater<int>> minHeap;
    int count=0;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        count++;
        maxHeap.push(num);
        
        if(!minHeap.empty() && minHeap.top()<maxHeap.top()){
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }

        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }

        else if(minHeap.size()>maxHeap.size()){
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        if(count%2==1) return (double)maxHeap.top();
        return (minHeap.top()+maxHeap.top())/2.0;
    }
};
