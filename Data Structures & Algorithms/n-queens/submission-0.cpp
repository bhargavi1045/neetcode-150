class Solution {
public:
    void recursiveHelper(int index, vector<int>& col, vector<int>& diagonal1,
vector<int>& diagonal2,vector<string>& board,vector<vector<string>>& ans, int n) {
        if (index == n) {
            ans.push_back(board);
            return;
        }

        for (int j = 0; j < n; j++) {
            if (find(col.begin(), col.end(), j) == col.end() &&
                find(diagonal1.begin(), diagonal1.end(), index + j) ==diagonal1.end() && find(diagonal2.begin(), diagonal2.end(), index - j) ==diagonal2.end()) {

                col.push_back(j);
                diagonal1.push_back(index + j);
                diagonal2.push_back(index - j);
                board[index][j] = 'Q';

                recursiveHelper(index + 1, col, diagonal1, diagonal2, board,ans,n);

                col.pop_back();
                diagonal1.pop_back();
                diagonal2.pop_back();
                board[index][j] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        vector<int> col;
        vector<int> diagonal1;
        vector<int> diagonal2;
        recursiveHelper(0, col, diagonal1, diagonal2, board, ans, n);
        return ans;
    }
};
