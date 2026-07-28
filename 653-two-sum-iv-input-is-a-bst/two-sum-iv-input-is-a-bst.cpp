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
    bool dfs(TreeNode* root, int k,unordered_set<int>& seen){
        if(root==NULL){
            return false;
        }

        int compliment=k-root->val;

        if(seen.count(compliment)){
            return true;
        }

        seen.insert(root->val);
        return dfs(root->left,k,seen)||dfs(root->right,k,seen);
    }
public:
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> seen;
        return dfs(root,k,seen);
    }
};