class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()%groupSize!=0) return false;
        unordered_map<int,int> mpp;
        for(int i=0;i<hand.size();i++){
            mpp[hand[i]]++;
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

        for(auto m : mpp){
            pq.push({m.first,m.second});
        }

        vector<pair<int,int>> a;
        while(!pq.empty()){

            int last=-1;
            int count=0;
            for(int i=0;i<groupSize && !pq.empty();i++){
                auto it=pq.top();
                pq.pop();

                int val=it.first;
                int freq=it.second;
                count++;
                if(last==-1 || last+1==val){
                    last=val;
                    if(freq>1) a.push_back({val,freq-1});
                }
                else if(last+1!=val) return false;
            }
            if(count!=groupSize) return false;

            for(int i=0;i<a.size();i++){
                pq.push(a[i]);
            }
            a.clear();
        }
        return true;
    }
};
