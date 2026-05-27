class Solution {
public:
    bool findWord(vector<vector<char>>&board,string &word,int index,int i,int j){
        if(index==word.size()){
            return true;
        }
        
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size())
        return false;

        if (board[i][j] == '.' || board[i][j] != word[index])
        return false;
        int drow[4]={1,-1,0,0};
        int dcol[4]={0,0,-1,1};
        bool ans=false;
        
        
            char value=board[i][j];
           board[i][j]='.';
           for(int k=0;k<4;k++){
              int di=i+drow[k];
              int dj=j+dcol[k];

              
                ans=ans || findWord(board,word,index+1,i+drow[k],j+dcol[k]);
              
           }
           board[i][j]=value;
        
        return ans;
    }
    bool exist(vector<vector<char>>& board, string word) {
        bool res=false;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]==word[0]){
                    res=res || findWord(board,word,0,i,j);
                }
            }
        }
        return res;
    }
};
