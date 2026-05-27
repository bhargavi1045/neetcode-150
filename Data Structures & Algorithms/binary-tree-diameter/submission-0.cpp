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
    int findMaxD(TreeNode* root,int &maxD){
        if(!root) return 0;
        int leftSide=findMaxD(root->left,maxD);
        int rightSide=findMaxD(root->right,maxD);
        maxD=max(maxD,leftSide+rightSide);
        return max(leftSide,rightSide)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int maxD=INT_MIN;
        findMaxD(root,maxD);
        return maxD;
    }
};
