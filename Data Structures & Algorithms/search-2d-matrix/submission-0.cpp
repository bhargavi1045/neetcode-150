class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        int low=0;
        int high=n*m-1;

        while(low<=high){
           int mid=low+(high-low)/2;
           
           int mcol=mid%m;
           int mrow=mid/m;

           if(matrix[mrow][mcol]==target) return true;
           else if(matrix[mrow][mcol]>target){
              high=mid-1;
           }
           else low=mid+1;
        }
        return false;
    }
};
