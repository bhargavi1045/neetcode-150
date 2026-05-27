class Solution {
public:
    int dfs(vector<vector<int>>&grid,int i,int j){
        if(grid[i][j]==2) return 0;
        grid[i][j]=2;
        
       
        int drow[4]={1,-1,0,0};
        int dcol[4]={0,0,-1,1};
        int area=1;

        for(int k=0;k<4;k++){
            int nrow=i+drow[k];
            int ncol=j+dcol[k];

            if(nrow>=0 && nrow<grid.size() && ncol>=0 && ncol<grid[0].size() && grid[nrow][ncol]==1){
              
                area+=dfs(grid,nrow,ncol);
            }
        }
        return area;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                   maxArea=max(maxArea,dfs(grid,i,j));
                }
            }
        }
        return maxArea;
    }
};
