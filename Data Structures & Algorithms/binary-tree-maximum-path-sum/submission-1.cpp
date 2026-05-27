/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int helper(TreeNode* root,int &maxSum){
        if(!root) return 0;

        int leftSide=helper(root->left,maxSum);
        int rightSide=helper(root->right,maxSum);
        
        int sum=root->val;
        if(leftSide>0) sum+=leftSide;
        if(rightSide>0) sum+=rightSide;

        maxSum=max(maxSum,sum);
        
        return root->val+max({0,leftSide,rightSide});
    }
    int maxPathSum(TreeNode* root) {
        int maxSum=INT_MIN;

        helper(root,maxSum);
        return maxSum;
    }
};
