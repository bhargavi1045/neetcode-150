class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>> pacificVisited(n,vector<int>(m,0));
        vector<vector<int>> atlanticVisited(n,vector<int>(m,0));
        queue<pair<int,int>> pacQ,atlQ;
        vector<vector<int>> result;
        //atlantic ocean;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==n-1 || j==m-1) {
                    atlanticVisited[i][j]=1;
                    atlQ.push({i,j});
                }
            }
        }
         
        //pacific ocean
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 || j==0) {
                    pacificVisited[i][j]=1;
                    pacQ.push({i,j});
                }
            }
        }
        auto bfs=[&](queue<pair<int,int>>&q,vector<vector<int>>&visited){
            int drow[4]={1,0,-1,0};
            int dcol[4]={0,1,0,-1};
            while(!q.empty()){
            auto it=q.front();
            q.pop();
            
            int row=it.first;
            int col=it.second;

            for(int i=0;i<4;i++){
                int nrow=drow[i]+row;
                int ncol=dcol[i]+col;
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && visited[nrow][ncol]!=1 && heights[nrow][ncol]>=heights[row][col]){
                    visited[nrow][ncol]=1;
                    q.push({nrow,ncol});
                }
            }
          }
        };
        bfs(pacQ,pacificVisited);
        bfs(atlQ,atlanticVisited);

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(pacificVisited[i][j]==1 && atlanticVisited[i][j]==1){
                    result.push_back({i,j});
                }
            }
        }
        return result;
    }
};
