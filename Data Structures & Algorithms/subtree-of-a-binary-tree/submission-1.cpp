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
    bool isSameTree(TreeNode* foundRoot,TreeNode* subRoot){
        if(!foundRoot && !subRoot) return true;
        if(!foundRoot || !subRoot || foundRoot->val!=subRoot->val) return false;
        return isSameTree(foundRoot->left,subRoot->left) && isSameTree(foundRoot->right,subRoot->right);
    }
    void findSubRootInTree(TreeNode* root,TreeNode* subRoot,vector<TreeNode*>&foundRoots){
        if(!root) return;
        if(root->val==subRoot->val){
            foundRoots.push_back(root);
        }
        findSubRootInTree(root->left,subRoot,foundRoots);
        findSubRootInTree(root->right,subRoot,foundRoots);
        
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        vector<TreeNode*> foundRoots;
        findSubRootInTree(root,subRoot,foundRoots);

        for(auto foundRoot : foundRoots){
            if(isSameTree(foundRoot,subRoot)) return true;
        }
        
        return false;

    }
};
