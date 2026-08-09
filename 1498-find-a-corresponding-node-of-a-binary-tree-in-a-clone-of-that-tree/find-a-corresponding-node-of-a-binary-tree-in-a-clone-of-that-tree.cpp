/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if(original==nullptr){
            return nullptr;
        }

        if(original==target){
            return cloned;
        }

        TreeNode* leftResult=getTargetCopy(original->left,cloned->left,target);

        if(leftResult!=nullptr){
            return leftResult;
        }
        return getTargetCopy(original->right,cloned->right,target);
    }
};