class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n=9;

        for(int i=0;i<9;i++){
            set<char> s;
            for(int j=0;j<9;j++){
                if(board[i][j]=='.') continue;
                if(s.count(board[i][j])) return false;
                s.insert(board[i][j]);
            }
        }

        for(int j=0;j<9;j++){
            set<char> s;
            for(int i=0;i<9;i++){
                if(board[i][j]=='.') continue;
                if(s.count(board[i][j])) return false;
                s.insert(board[i][j]);
            }
        }

        for(int block=0;block<9;block++){
            set<char> s;
            int row=(block/3)*3;
            int col=(block%3)*3;

            for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                    if(board[row+i][col+j]=='.') continue;
                    if(s.count(board[row+i][col+j])) return false;
                    s.insert(board[row+i][col+j]);
                }
            }
        }
        return true;
    }
};