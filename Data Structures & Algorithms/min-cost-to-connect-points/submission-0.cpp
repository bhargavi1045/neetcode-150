class Solution {
public:
    class DisjointSet{
        vector<int> parent;
        vector<int> rank;
        vector<int> size;
        
        public:
        DisjointSet(int n){
           parent.resize(n);
           size.resize(n,1);
           rank.resize(n,0);

           for(int i=0;i<n;i++) parent[i]=i;
        }

        int findParent(int node){
            if(parent[node]==node) return node;
            else return parent[node]=findParent(parent[node]);
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

    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<vector<int>> edges;

        for(int i=0;i<points.size();i++){
            for(int j=i+1;j<points.size();j++){
                edges.push_back({abs(points[j][0]-points[i][0])+abs(points[j][1]-points[i][1]),i,j});
            }
        }

        sort(edges.begin(),edges.end());
        DisjointSet ds(points.size());
        int cost=0;
        for(auto edge : edges){
            int wt=edge[0];
            int u=edge[1];
            int v=edge[2];

            if(ds.unionBySize(u,v)) cost+=wt;
        }
        return cost;
    }
};
