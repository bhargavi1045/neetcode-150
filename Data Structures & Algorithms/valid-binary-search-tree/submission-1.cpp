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
    bool checkIsValid(TreeNode* root,int start,int end){
        if(!root) return true;
        if(root->val<=start || root->val>=end) return false;
        return checkIsValid(root->left,start,root->val) && checkIsValid(root->right,root->val,end);
    }
    bool isValidBST(TreeNode* root) {
        int start=INT_MIN;
        int end=INT_MAX;
        return checkIsValid(root,start,end);
    }
};
