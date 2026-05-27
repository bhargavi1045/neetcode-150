class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int INF=2147483647;
        queue<pair<int,int>> q;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==0){
                    q.push({i,j});
                }
            }
        }

        while(!q.empty()){
            auto it=q.front();
            q.pop();

           
            int x=it.first;
            int y=it.second;


            int drow[4]={1,-1,0,0};
            int dcol[4]={0,0,-1,1};

            for(int i=0;i<4;i++){
                int nx=x+drow[i];
                int ny=y+dcol[i];

                if(nx>=0 && nx<grid.size() && ny>=0 && ny<grid[0].size() && grid[nx][ny]==INF){
                    grid[nx][ny]=grid[x][y]+1;
                    q.push({nx,ny});
                }
            }
        }

      
    }
};
