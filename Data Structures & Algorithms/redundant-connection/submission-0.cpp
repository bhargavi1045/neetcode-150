class Solution {
public:
    class DisjointSet{
        vector<int> parent;
        vector<int> rank;
        vector<int> size;
        public:
        DisjointSet(int n){
            parent.resize(n+1);
            size.resize(n+1,1);
            rank.resize(n+1,0);

            for(int i=1;i<n+1;i++) parent[i]=i;
        }
        int findParent(int node){
            if(parent[node]==node) return node;
            return parent[node]=findParent(parent[node]);
        }
        bool unionBySize(int u,int v){
            int pu=findParent(u);
            int pv=findParent(v);

            if(pu==pv) return false;

            
            if(size[pu]>size[pv]){
                size[pu]+=size[pv];
                parent[pv]=pu;
            }
            else{
                size[pv]+=size[pu];
                parent[pu]=pv;
            }
            return true;
        }
        bool unionByRank(int u,int v){
            int pu=findParent(u);
            int pv=findParent(v);
            
            if(pu==pv) return false;

            if(rank[pu]>rank[pv]){
                parent[pv]=pu;
            }
            else if(rank[pv]>rank[pu]){
                parent[pu]=pv;
            }
            else{
                rank[pv]=rank[pv]+1;
                parent[pu]=pv;
            }
            return true;
        }
    };
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int maxNum=0;
        for(auto edge : edges){
            maxNum=max({edge[0],edge[1],maxNum});
        }
        if(edges.size()<maxNum-1) return {};

        int possibleEdge=0;
        vector<int> redundant;

 
        DisjointSet ds(maxNum);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];

            if(ds.unionBySize(u,v)) possibleEdge++;
            else{
                if(!redundant.empty()){
                    redundant.clear();
                }
                redundant.push_back(edges[i][0]);
                redundant.push_back(edges[i][1]);
            }
        }

        if(possibleEdge!=maxNum-1) return {};
        return redundant;
    }
};