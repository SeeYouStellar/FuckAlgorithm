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
    int sum = 0;
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == NULL) return false;
        if(root->left == NULL && root->right == NULL) {
            if(sum+root->val == targetSum) return true;
            else return false;
        }
        sum += root->val;
        bool l = hasPathSum(root->left, targetSum);
        bool r = hasPathSum(root->right, targetSum);
        sum -= root->val;
        return l||r;  // 子路径里有一条能满足条件即返回true
    }
};