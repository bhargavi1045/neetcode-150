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

        void unionBySize(int u,int v){
            int pu=findParent(u);
            int pv=findParent(v);
            
            if(pu==pv) return;

            if(size[pu]>size[pv]){
                size[pu]+=size[pv];
                parent[pv]=pu;
            }
            else{
                size[pv]+=size[pu];
                parent[pu]=pv;
            }
        }

        void unionByRank(int u,int v){
            int pu=findParent(u);
            int pv=findParent(v);
            
            if(pu==pv) return;

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
        }
    };
    int countComponents(int n, vector<vector<int>>& edges) {
        DisjointSet ds(n);

        for(auto edge : edges){
            int u=edge[0];
            int v=edge[1];
            ds.unionBySize(u,v);
        }
        
        int components=0;
        for(int i=0;i<n;i++){
           if(ds.findParent(i)==i){
            components++;
           }
        }
        return components;
    }
};
