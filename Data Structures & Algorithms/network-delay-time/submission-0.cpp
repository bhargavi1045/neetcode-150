class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);

        for(auto time : times){
            int u=time[0];
            int v=time[1];
            int t=time[2];
            adj[u].push_back({v,t});
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

        vector<int> timeReach(n+1,INT_MAX);

        timeReach[k]=0;
        pq.push({0,k});

        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            
            int tm=it.first;
            int node=it.second;

            if(timeReach[node]<tm) continue;

            for(auto ele : adj[node]){
                int adjNode=ele.first;
                int ti=ele.second;

                if(timeReach[adjNode]>tm+ti){
                    timeReach[adjNode]=tm+ti;
                    pq.push({tm+ti,adjNode});
                }
            }
        }

        int maxTime=0;
        for(int i=1;i<=n;i++){
            if(timeReach[i]==INT_MAX) return -1;
            maxTime=max(maxTime,timeReach[i]);
        }

        return maxTime;
    }
};
