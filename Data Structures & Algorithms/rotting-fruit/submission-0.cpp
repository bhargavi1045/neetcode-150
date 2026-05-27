class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        int freshOrange=0;
        queue<pair<pair<int,int>,int>> q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1) freshOrange++;
                else if(grid[i][j]==2){
                    q.push({{i,j},0});
                }
            }
        }

        vector<vector<int>> rotten(n,vector<int>(m,0));
        int maxTime=0;
        int count=0;

        while(!q.empty()){
            auto rottenOrange=q.front();
            q.pop();

            int rottenX=rottenOrange.first.first;
            int rottenY=rottenOrange.first.second;
            int timeLapse=rottenOrange.second;
            maxTime=max(maxTime,timeLapse);

            int drow[4]={1,-1,0,0};
            int dcol[4]={0,0,1,-1};

            for(int i=0;i<4;i++){
                int newRow=drow[i]+rottenX;
                int newCol=dcol[i]+rottenY;

                if(newRow>=0 && newRow<n && newCol>=0 && newCol<m && grid[newRow][newCol]==1 && rotten[newRow][newCol]!=1){
                    count++;
                    rotten[newRow][newCol]=1;
                    q.push({{newRow,newCol},timeLapse+1});
                }
            }
        }
        if(freshOrange!=count) return -1;
        return maxTime;
    }
};
