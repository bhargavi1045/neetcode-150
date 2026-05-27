class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();

        vector<vector<int>> level(n,vector<int>(n,INT_MAX));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;

        pq.push({grid[0][0],{0,0}});
        int drow[4]={0,0,-1,1};
        int dcol[4]={-1,1,0,0};

        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();

            int maxLevel=it.first;
            int x=it.second.first;
            int y=it.second.second;

            if(maxLevel>=level[x][y]) continue;

            level[x][y]=maxLevel;

            for(int i=0;i<4;i++){
                int nx=x+drow[i];
                int ny=y+dcol[i];

                if(nx>=0 && nx<n && ny>=0 && ny<n){
                   if(max(maxLevel,grid[nx][ny])<level[nx][ny]){
                      pq.push({max(maxLevel,grid[nx][ny]),{nx,ny}});
                   }
                }
            }
        }

        return level[n-1][n-1];
    }
};
