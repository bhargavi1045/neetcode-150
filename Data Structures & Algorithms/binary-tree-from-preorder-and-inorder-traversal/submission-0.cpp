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
    TreeNode* build(vector<int>&preorder, vector<int>& inorder, int start, int end,int &index){
        if(end<start) return NULL;
        if(index>=inorder.size()) return NULL;

        int value=preorder[index];
        int i=find(inorder.begin(),inorder.end(),value)-inorder.begin();
        index++;

        TreeNode* root=new TreeNode(value);
        root->left=build(preorder,inorder,start,i-1,index);
        root->right=build(preorder,inorder,i+1,end,index);

        return root;

    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=preorder.size();
        int index=0;

        return build(preorder,inorder,0,n-1,index);
    }
};
