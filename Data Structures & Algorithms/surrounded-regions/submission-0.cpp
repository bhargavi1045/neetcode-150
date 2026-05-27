class Solution {
public:
     void dfs(vector<vector<char>>&board,vector<vector<int>>&visited,int nodeX,int nodeY){
        if(visited[nodeX][nodeY]) return;
        visited[nodeX][nodeY]=1;

        board[nodeX][nodeY]='Y';

        int drow[4]={0,0,-1,1};
        int dcol[4]={1,-1,0,0};

        for(int i=0;i<4;i++){
            int nrow=nodeX+drow[i];
            int ncol=nodeY+dcol[i];
            if(nrow>=0 && nrow<board.size() && ncol>=0 && ncol<board[0].size() && board[nrow][ncol]=='O'){
                dfs(board,visited,nrow,ncol);
            }
        }

        
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        
        vector<vector<int>> visited(n,vector<int>(m,0));

        for(int i=0;i<n;i++){
            if(board[i][0]=='O' && !visited[i][0] ) dfs(board,visited,i,0);
            if(board[i][m-1]=='O' && !visited[i][m-1]) dfs(board,visited,i,m-1);
        }

        for(int j=0;j<m;j++){
            if(board[0][j]=='O' && !visited[0][j]) dfs(board,visited,0,j);
            if(board[n-1][j]=='O' && !visited[n-1][j]) dfs(board,visited,n-1,j);
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
               if(board[i][j]=='Y'){
                  board[i][j]='O';
               }
               else if(board[i][j]=='O'){
                  board[i][j]='X';
               }
            }
        }
    }
};