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
    int checkBalanced(TreeNode* root){
        if(!root) return 0;
        int leftSide=checkBalanced(root->left);
        int rightSide=checkBalanced(root->right);
        if(leftSide==-1 || rightSide==-1 || abs(leftSide-rightSide)>1) return -1;
        return max(leftSide,rightSide)+1; 
    }
    bool isBalanced(TreeNode* root) {
        return checkBalanced(root)!=-1;
    }
};
