class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses,0);
        vector<int> res;
        for(int i=0;i<prerequisites.size();i++){
            int u=prerequisites[i][0];
            int v=prerequisites[i][1];
            adj[v].push_back(u);
            indegree[u]++;
        }
        
        queue<int> q;
        
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0) q.push(i);
        }

        while(!q.empty()){
            auto node=q.front();
            q.pop();
            res.push_back(node);

            for(auto adjNode : adj[node]){
                indegree[adjNode]--;
                if(indegree[adjNode]==0) q.push(adjNode);
            }
        }

        if(res.size()!=numCourses) return {};
        return res;
    }
};
