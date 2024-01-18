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
    map<long long, int> st;
    int res = 0;
    void find(TreeNode* root, long long sum, int targetSum) {
        if(root == NULL) return ;

        sum += root->val;
        if(st.count(sum - targetSum) != 0) res+=st[sum - targetSum]; // 寻找缀和为sum - targetSum的父类节点

        st[sum]++;
        find(root->left, sum, targetSum);
        find(root->right, sum, targetSum);
        st[sum]--;
    }
    int pathSum(TreeNode* root, int targetSum) {
        st[0] = 1;  // 为了在寻找路径时找到带根节点的路径
        find(root, 0, targetSum);
        return res;
    }
};