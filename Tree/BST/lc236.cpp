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
    TreeNode* CommonAncestor;
    bool find(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return false;
        bool l = find(root->left, p, q);
        bool r = find(root->right, p, q);
        if((l && r) || ((l||r) && (root == p||root==q))) {
            CommonAncestor = root;
            return true;
        }else if(l || r || root == p||root==q) {
            return true;
        }else {
            return false;
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        find(root, p, q);
        return CommonAncestor;
    }
};