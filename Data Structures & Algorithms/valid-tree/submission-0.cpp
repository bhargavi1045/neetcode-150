class Solution {
public:
    bool valid(int n,vector<vector<int>>&adj,vector<int>&visited,int node,bool &ans,int parent){
        visited[node]=1;
        for(auto adjNode : adj[node]){
            if(!visited[adjNode]){
                ans=ans && valid(n,adj,visited,adjNode,ans,node);
            }
            else if(adjNode!=parent){
                return false;
            }
        }
        return ans;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size()!=n-1) return false;
        vector<vector<int>> adj(n);
        for(auto edge : edges){
            int u=edge[0];
            int v=edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        bool ans=true;
        vector<int> visited(n,0);
        int count=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                count++;
                valid(n,adj,visited,i,ans,-1);
                if(count>1) return false;
            }
        }
        return ans;
    }
};
