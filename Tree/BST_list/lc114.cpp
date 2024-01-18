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
    TreeNode* findleaf(TreeNode* root) {
        if(root->right == NULL) return root;
        TreeNode* leaf = findleaf(root->right);
        return leaf;
    }
    void flatten(TreeNode* root) {
        if(root == NULL) return;
        flatten(root->left);
        flatten(root->right);
        if(root->left != NULL && root->right != NULL) {
            TreeNode* leftLeaf = findleaf(root->left);
            leftLeaf->right = root->right;
            root->right = root->left;
            root->left = NULL;
        } else if(root->left != NULL) {
            root->right = root->left;
            root->left = NULL;
        } 
    }
};

// 类似AVL的右旋