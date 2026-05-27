class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses);
        vector<vector<int>> adj(numCourses);
        int count=0;
        queue<int> q;
        for(int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        for(int i=0;i<prerequisites.size();i++){
            indegree[prerequisites[i][0]]++;
        }

        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                count++;
                q.push(i);
            }
        }

        while(!q.empty()){
            auto course=q.front();
            q.pop();

            for(auto node : adj[course]){
                indegree[node]--;
                if(indegree[node]==0){
                    q.push(node);
                    count++;
                } 
            }
        }
        if(count==numCourses) return true;
        return false;
    }
};
