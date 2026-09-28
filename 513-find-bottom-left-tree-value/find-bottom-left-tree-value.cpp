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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> s;
        s.push(root);

        TreeNode* node=nullptr;

        while(!s.empty()){
            node=s.front();
            s.pop();

            if(node->right){
                s.push(node->right);
            }
            if(node->left){
                s.push(node->left);
            }
        }
        return node->val;
    }
};