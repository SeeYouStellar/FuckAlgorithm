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
    int idx = 0;
    int kthSmallest(TreeNode* root, int k) {
        if(root == NULL) return 0;
        
        int l = kthSmallest(root->left, k);
        idx ++;
        if(idx == k) {
            return root->val;
        }
        int r = kthSmallest(root->right, k);
        return (l==-1?0:l)+(r==-1?0:r);
    }
};

// 中序遍历bst，输出为升序序列