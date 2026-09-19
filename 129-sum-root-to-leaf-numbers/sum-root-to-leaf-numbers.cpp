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
private:
    int dfs(TreeNode* node ,int curr){
        if(node == nullptr){
            return 0;
        }

        curr=curr*10+node->val;

        if(node->left==nullptr && node->right==nullptr){
            return curr;
        }

        int leftSum=dfs(node->left,curr);
        int rightSum=dfs(node->right,curr);

        return leftSum+rightSum;
    }
public:
    int sumNumbers(TreeNode* root) {
        return dfs(root,0);
    }
};