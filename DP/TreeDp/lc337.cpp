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
    unordered_map<TreeNode*, pair<int, int>> us;
    void robdfs(TreeNode* root){
        if(!root) return;
        robdfs(root->left);
        robdfs(root->right);
        int choose = root->val+us[root->left].second+us[root->right].second;
        int notchoose = max(us[root->left].second, us[root->left].first)+max(us[root->right].second, us[root->right].first);
        us[root] = make_pair(choose, notchoose);
    }
    int rob(TreeNode* root) {
        robdfs(root);
        return max(us[root].first, us[root].second);
    }
};

/*
从下往上dp
*/ 