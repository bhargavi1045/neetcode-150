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
    void findGoodNodes(TreeNode* root,int maxi,int &countOfGoodNodes){
        if(!root) return;
        if(root->val>=maxi){
          countOfGoodNodes++;
          maxi=root->val;
        }
        findGoodNodes(root->left,maxi,countOfGoodNodes);
        findGoodNodes(root->right,maxi,countOfGoodNodes);
    }
    int goodNodes(TreeNode* root) {
        int maxi=INT_MIN;
        int countOfGoodNodes=0;

        findGoodNodes(root,maxi,countOfGoodNodes);

        return countOfGoodNodes;
    }
};
