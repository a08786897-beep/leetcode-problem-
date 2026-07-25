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

    int calculation(TreeNode* root,int currentsum){
        if(root==nullptr){
            return 0;
        }
        currentsum=(currentsum<<1) | root->val;

        if(root->left==nullptr && root->right==nullptr){
            return currentsum;
        }
        return calculation(root->left,currentsum)+calculation(root->right,currentsum);
    }
    int sumRootToLeaf(TreeNode* root) {
       return calculation(root,0);
        
    }
};