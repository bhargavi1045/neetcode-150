class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();

        int top=0;
        int bottom=n-1;
        int left=0;
        int right=m-1;
        vector<int> spiral={};

        while(left<=right && top<=bottom) {

            for(int j=left;j<=right;j++) {
                spiral.push_back(matrix[top][j]);
            }
            top++;

            for(int i=top;i<= bottom;i++) {
                spiral.push_back(matrix[i][right]);
            }
            right--;

            if(top<=bottom){
            for (int j=right;j>=left;j--) {
                spiral.push_back(matrix[bottom][j]);
            }
            bottom--;
            }

            if(left<=right){
            for (int i=bottom;i>=top;i--) {
                spiral.push_back(matrix[i][left]);
            }
            left++;
            }
        }
        return spiral;
    }
};