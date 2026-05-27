class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        vector<vector<int>> adj(26);
        vector<int> indegree(26, 0);
        vector<bool> present(26, false);
        queue<int> q;
        
        for (auto &w : words) {
            for (char c : w) {
                present[c - 'a'] = true;
            }
        }
        
        for (int i = 0; i < words.size() - 1; i++) {
            string now = words[i];
            string next = words[i + 1];
            int k = 0;
            
            while (k < now.size() && k < next.size() && now[k] == next[k]) {
                k++;
            }
            
            if (k==next.size() && k<now.size()) return "";
            
            if (k < now.size() && k < next.size()) {
                adj[now[k] - 'a'].push_back(next[k] - 'a');
                indegree[next[k] - 'a']++;
            }
        }
        
        for (int i = 0; i < 26; i++) {
            if (present[i] && indegree[i] == 0) {
                q.push(i);
            }
        }
        
        string order = "";
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            order.push_back(char(node + 'a'));
            
            for (auto adjNode : adj[node]) {
                indegree[adjNode]--;
                if (indegree[adjNode] == 0) {
                    q.push(adjNode);
                }
            }
        }
        
        for (int i = 0; i < 26; i++) {
            if (present[i] && indegree[i] > 0) return "";
        }
        
        return order;
    }
};
