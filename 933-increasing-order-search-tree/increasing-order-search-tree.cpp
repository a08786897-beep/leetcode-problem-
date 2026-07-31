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
    TreeNode* dummy=new TreeNode(0);
    TreeNode* curr=dummy;
    TreeNode* increasingBST(TreeNode* root) {
        if(root==NULL){
            return NULL;
        }

        increasingBST(root->left);
        root->left=NULL;
        curr->right=root;
        curr=root;
        increasingBST(root->right);
        return dummy->right;
    }
};