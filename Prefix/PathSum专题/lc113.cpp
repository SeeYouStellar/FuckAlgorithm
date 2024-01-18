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
    vector<int> path;
    vector<vector<int>> res;
    void find(TreeNode* root, int targetSum) {
        if(root == NULL) return ;
        if(root->left == NULL && root->right == NULL) {
            if(sum+root->val == targetSum) {
                path.push_back(root->val);
                res.push_back(path);
                path.erase(path.end()-1);
            }
            return;
        }
        sum += root->val;
        path.push_back(root->val);
        find(root->left, targetSum);
        find(root->right, targetSum);
        path.erase(path.end()-1);
        sum -= root->val;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        find(root, targetSum);
        return res;
    }
};