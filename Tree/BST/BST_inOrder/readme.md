### [剑指 Offer 36. 二叉搜索树与双向链表](https://leetcode.cn/problems/er-cha-sou-suo-shu-yu-shuang-xiang-lian-biao-lcof/)

> 首先二叉搜索树（$BST$）的最重要的一个特征就是中序遍历是升序的，并且题目要求的双向链表也是需要升序排列，那么就很容易将这两点结合起来。

**思路：** 按中序遍历遍历整棵树，每个节点**$cur$**都设置一个前驱节点$ pre $(中序遍历顺序上上一个遍历到的节点)。理论上每个节点与其前驱节点之间相互连接，即可构建出双向链表。但注意前驱节点不是通过递归参数的形式进行更新，而是通过外部记录，手动更新。另外，题目要求返回双向链表首节点，那么中序遍历到的第一个节点即为$head$。

**举个栗子：**下图中的中序遍历顺序是1->2->3->4->5，所以到达1节点时，$cur$为1节点，而在此之前$pre$一直未更新，为$NULL$，记录$head$为1节点，遍历1节点后将$pre$更新为$cur$，也就是1节点。当遍历到2节点时，$pre$为1，$cur$为2，此时再将两者相互连接。注意遍历到3时，$pre$为2，$cur$为3；遍历到4时，$pre$为3，$cur$为4，那么就自动解决了左子树的最大值节点与根节点相互连接。最后遍历完5后，$pre$为5，将其与先前记录的headxiang'hu

![img](https://assets.leetcode.com/uploads/2018/10/12/bstdlloriginalbst.png)

### [剑指 Offer 68 - I. 二叉搜索树的最近公共祖先](https://leetcode.cn/problems/er-cha-sou-suo-shu-de-zui-jin-gong-gong-zu-xian-lcof/)

> $BST$最基本的性质，也是最容易忽视的性质：当一个节点的值小于当前节点值，那么这个节点一定在当前节点的左子树中；反之在右子树中

**思路：**要想找最近公共祖先，需要知道**两个节点在二叉树中相对位置**的所有情况：

1. 两个节点分别在当前节点$root$的两侧，那么$root$即为最近公共祖先
2. 两个节点在当前节点的（左/右）侧，那么最近公共祖先就在当前节点的（左/右）子树
3. 其中一个节点就是当前节点，那么当前节点就是最近公共祖先

问题来了，如何确定节点与当前节点的位置关系，本题是$BST$，并且是无重复节点，根据**节点值大小**关系很容易判断。上述三种情况只需要判断2，只要不符合2，那么当前节点即为最近公共祖先

### [剑指 Offer 68 - II. 二叉树的最近公共祖先](https://leetcode.cn/problems/er-cha-shu-de-zui-jin-gong-gong-zu-xian-lcof/)

> 当只是一棵二叉树时，两个节点在二叉树中的位置是不会变得，依然有三种情况。

**思路：**重新考虑如何获取两个节点与根节点的相对关系即可。递归函数返回值代表是否有$p$或$q$。那么三种相对关系可以由左右子树函数返回值的组合来判断

1. $p,q$在当前子树的两侧，即左子树返回值$lson$和右子树$rson$返回值同时为$true$

2. $p/q$为当前节点，另一个$p/q$在当前节点的子树内，即$lson$和$rson$有一个值为$true$一个值为$false$，并且当前节点值与$p/q$相同

   **以上两种情况最近公共祖先均为当前节点$root$**

3. 当$p,q$都在当前节点的某一个子树中时，最近公共祖先就不是$root$，仔细想其实这种情况下，肯定$lson$和$rson$肯定有一个返回值为$true$，因为当回溯到这个节点时，早就已经发生过第二种情况了。

```c++
class Solution {
public:
    TreeNode* ans;
    bool dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) return false;
        bool lson = dfs(root->left, p, q);
        bool rson = dfs(root->right, p, q);
        if ((lson && rson) || ((root->val == p->val || root->val == q->val) && (lson || rson))) {
            ans = root;
        } 
        // 当左子树或右子树中有p, q时或者当前节点值就是p或q时，返回值为true，代表当前子树中含有p或q
        return lson || rson || (root->val == p->val || root->val == q->val); 
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, p, q);
        return ans;
    }
};
```

