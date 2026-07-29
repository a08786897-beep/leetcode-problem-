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
    void get(TreeNode* root,vector<int>& leave){
        if(root==nullptr){
            return;
        }
        if(root->left ==nullptr && root->right==nullptr){
            leave.push_back(root->val);
            return;
        }
        get(root->left,leave);
        get(root->right,leave);


    }
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leave1; 
        vector<int> leave2;

        get(root1,leave1); 
        get(root2,leave2); 

        return leave1==leave2;
    }
};