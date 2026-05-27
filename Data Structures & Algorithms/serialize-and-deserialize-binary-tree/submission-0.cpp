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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans="";
        
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            auto node=q.front();
            q.pop();

            if(node==NULL) {
                ans+="#,";
                continue;
            }
            else ans+=to_string(node->val)+",";
            q.push(node->left);
            q.push(node->right);
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        string str=data;
        stringstream ss(str);
        queue<TreeNode*> q;

        getline(ss,str,',');
        if(str=="#") return NULL;
        TreeNode* root=new TreeNode(stoi(str));
        q.push(root);

        while(!q.empty()){
            auto node=q.front();
            q.pop();

            getline(ss,str,',');
            if(str=="#"){
                node->left=NULL;
            }
            else{
                node->left=new TreeNode(stoi(str));
                q.push(node->left);
            }

            getline(ss,str,',');
            if(str=="#"){
                node->right=NULL;
            }
            else{
                node->right=new TreeNode(stoi(str));
                q.push(node->right);
            }
        }
        return root;
    }
};
