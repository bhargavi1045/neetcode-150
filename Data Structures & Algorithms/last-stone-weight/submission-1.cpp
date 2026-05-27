class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap;

        for(int i=0;i<stones.size();i++){
            maxHeap.push(stones[i]);
        }

        while(!maxHeap.empty()){
            int first=maxHeap.top();
            maxHeap.pop();
            int second=-1;
            if(!maxHeap.empty()){
                second=maxHeap.top();
                maxHeap.pop();
            }
            if(second==-1) return first;
            else{
                if(first!=second){
                    maxHeap.push(abs(first-second));
                }
                else maxHeap.push(0);
            }
        }

        return -1;
    }
};
