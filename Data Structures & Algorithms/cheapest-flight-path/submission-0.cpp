class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> distance(n,INT_MAX);
        vector<vector<pair<int,int>>> adj(n);

        for(auto flight : flights){
            int from=flight[0];
            int to=flight[1];
            int price=flight[2];
            adj[from].push_back({to,price});
        }

        queue<pair<int,pair<int,int>>> q;
        q.push({0,{src,0}});

        while(!q.empty()){
            auto it=q.front();
            q.pop();

            int price=it.first;
            int node=it.second.first;
            int stops=it.second.second;

            if(stops>k+1) continue;
            if(stops==k+1){
                if(node==dst) {
                    distance[node]=price;
                }
                else continue;
            }

            for(auto it : adj[node]){
                int node=it.first;
                int pr=it.second;

                if(distance[node]>pr+price) {
                    q.push({price+pr,{node,stops+1}});
                    distance[node]=price+pr;
                }
            }
        }
        if(distance[dst]==INT_MAX) return -1;
        else return distance[dst];
    }
};
