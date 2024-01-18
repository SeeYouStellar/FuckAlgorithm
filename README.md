# LeetCode ![language](https://img.shields.io/badge/language-C%2B%2B-yellow.svg) ![language](https://img.shields.io/badge/language-Golang-yellow.svg)

LeetCode 代码和题解集合

### 1. BFS


### 2. DFS


### 3. BinarySearch
| 题     | 笔记 |
| ----------- | ----------- |
|[lc6929 数组的最大美丽值](https://leetcode.cn/problems/maximum-beauty-of-an-array-after-applying-operation/)|[最大连续子串](binarySearch\lc6929.md)|
|[lc34](https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array/description/?envType=study-plan-v2&envId=top-100-liked)|[二分及其越界判断](binarySearch\lc34.cpp)|
|[lc33](https://leetcode.cn/problems/search-in-rotated-sorted-array/description/?envType=study-plan-v2&envId=top-100-liked)|[非严格递增二分](binarySearch\lc33.cpp)|


#### 最大值最小化/最小值最大化问题
|题|笔记|
| ----------- | ----------- |
|[lc2560 打家劫舍 IV](https://leetcode.cn/problems/house-robber-iv/description/)|[最大值最小化问题+DP](DP\打家劫舍专题\lc2560.cpp)|

### 4. TwoPointers
| 题     | 笔记 |
| ----------- | ----------- |
|[lc6954 统计和小于目标的下标对数目](https://leetcode.cn/problems/count-pairs-whose-sum-is-less-than-target/description/)|[排序+双指针](two_pointers\lc6954.go)|
|[lc2831 找出最长等值子数组](https://leetcode.cn/problems/find-the-longest-equal-subarray/description/)|[分组+双指针](MonotonicQueue\lc2831.md)|
|[lc15 三树之和](https://leetcode.cn/problems/3sum/description/?envType=study-plan-v2&envId=top-100-liked)|[双指针](two_pointers\lc15.cpp)|
|[lc763 划分字母区间](https://leetcode.cn/problems/partition-labels/description/?envType=study-plan-v2&envId=top-100-liked)|[双指针+贪心](two_pointers\lc763.cpp)|
|[lc11 盛最多水的容器](https://leetcode.cn/problems/container-with-most-water/description/?envType=study-plan-v2&envId=top-100-liked)|[双指针](two_pointers\lc11.cpp)|

### 5. BranchBound


### 6. DP
| 题     | 笔记 |
| ----------- | ----------- |
|[lc1911 最大子序列交替和](https://leetcode.cn/problems/maximum-alternating-subsequence-sum/)|[股票买卖问题类型](DP\buy_stocks_time\lc1911.go)|
|[lc5 最长回文子串](https://leetcode.cn/problems/longest-palindromic-substring/)|[回文问题类型1](DP\匹配问题\Palindrome\lc5.go)[CPP版本](DP\匹配问题\Palindrome\lc5.cpp)|
|[lc647 回文子串](https://leetcode.cn/problems/palindromic-substrings/)|[回文问题类型2](DP\匹配问题\Palindrome\lc647.go)|
|[lc53 最大子数组和](https://leetcode.cn/problems/maximum-subarray/)|[最大子串和问题**母题**](DP\子串\lc53.go)|
|[]()|[LCS/LIS](DP\子序列\readme.md)|
|[lc918 环形子数组的最大和](https://leetcode.cn/problems/maximum-sum-circular-subarray/)|[最大子串问题2](DP\子串\lc918.md)|
|[1289. 下降路径最小和 II](https://leetcode.cn/problems/minimum-falling-path-sum-ii/description/)|[二维DP及其空间/时间复杂度优化-数组压缩](DP\two_dimention_dp\lc1289.md)|
|[lc2830 销售利润最大化](https://leetcode.cn/problems/maximize-the-profit-as-the-salesman/description/)|[排序+二分+DP](DP\others\lc2830.cpp)|
|[lc1235 规划兼职工作](https://leetcode.cn/problems/maximum-profit-in-job-scheduling/description/)|[排序+二分+DP](DP\others\lc1235.cpp)|
|[lc2008 出租车的最大盈利](https://leetcode.cn/problems/maximum-earnings-from-taxi/description/)|[排序+二分+DP](DP\others\lc2008.cpp)|
|[lc416 分割等和子集](https://leetcode.cn/problems/partition-equal-subset-sum/description/)|[01背包问题](DP\Bag\01Bag\lc416.cpp)|
|[lc322 零钱兑换](https://leetcode.cn/problems/coin-change/description/)|[完全背包问题](DP\Bag\CompleteBag\lc322.cpp)|
|[lc518 零钱兑换II](https://leetcode.cn/problems/coin-change-ii/description/)|[完全背包问题](DP\Bag\CompleteBag\lc518.cpp)|
|[lc279完全平方数](https://leetcode.cn/problems/perfect-squares/)|[完全背包问题](DP\Bag\CompleteBag\lc279.cpp)|
|[lc337 打家劫舍 III](https://leetcode.cn/problems/house-robber-iii/)|[TreeDP](DP\TreeDp\lc337.cpp)|
|[lc834 树中距离之和](https://leetcode.cn/problems/sum-of-distances-in-tree/)|[TreeDP](DP\TreeDp\lc834.md)|
|[lc823 带因子的二叉树](https://leetcode.cn/problems/binary-trees-with-factors/description/)|[排序+哈希表+树形DP](DP\TreeDp\lc823.cpp)|
|[lc42 接雨水](https://leetcode.cn/submissions/detail/468626240/)|[一维DP](DP\lc42.cpp)|
|[lc139 单词拆分](https://leetcode.cn/problems/word-break/?envType=study-plan-v2&envId=top-100-liked)|[字符串DP](DP\others\lc139.cpp)|
|[lc32 最长有效括号](https://leetcode.cn/problems/longest-valid-parentheses/description/?envType=study-plan-v2&envId=top-100-liked)|[括号匹配类DP](DP\匹配问题\括号问题\lc32.cpp)|

#### 打家劫舍专题（力扣）
|题|笔记|
| ----------- | ----------- |
|[lc198 打家劫舍 I](打家劫舍)|[DP](DP\打家劫舍专题\lc198.cpp)|
|[lc213 打家劫舍 II](https://leetcode.cn/problems/house-robber-ii/)|[DP](DP\打家劫舍专题\lc213.cpp)|
|[lc337 打家劫舍 III](https://leetcode.cn/problems/house-robber-iii/)|[TreeDP](DP\TreeDp\lc337.cpp)|
|[lc2560 打家劫舍 IV](https://leetcode.cn/problems/house-robber-iv/description/)|[最大值最小化问题+DP](DP\打家劫舍专题\lc2560.cpp)|

### 7. Graph


### 8. Tree


#### Binary Tree
| 题     | 笔记 |
| ----------- | ----------- |
| [lc979 在二叉树中分配硬币](https://leetcode.cn/problems/distribute-coins-in-binary-tree/) |[:memo:](Tree\BST\lc979.md)|
| [lc230 二叉搜索树中第K小的元素](https://leetcode.cn/problems/kth-smallest-element-in-a-bst/description/?envType=study-plan-v2&envId=top-100-liked) |[中序遍历](Tree\in_pre_postOrder\lc230.cpp)|
| [lc114 二叉树展开为链表](https://leetcode.cn/problems/flatten-binary-tree-to-linked-list/description/?envType=study-plan-v2&envId=top-100-liked) |[二叉树+链表+旋转](Tree\BST_list\lc114.cpp)|
| [lc236 二叉树的最近公共祖先](https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-tree/description/?envType=study-plan-v2&envId=top-100-liked) |[二叉树+分类讨论](Tree\BST\lc236.cpp)|
| [lc98 验证二叉搜索树](https://leetcode.cn/problems/validate-binary-search-tree/?envType=study-plan-v2&envId=top-100-liked) |[BST特性](Tree\BST\lc98.cpp)|

#### PathSum 专题
| [lc437 路径总和 III](https://leetcode.cn/problems/path-sum-iii/description/?envType=study-plan-v2&envId=top-100-liked) |[前缀和+二叉树](Prefix\PathSum专题\lc437.cpp)|
| [lc112 路径总和 I](https://leetcode.cn/problems/path-sum/description/) |[递归+二叉树](Prefix\PathSum专题\lc112.cpp)|
| [lc113 路径总和 II](https://leetcode.cn/problems/path-sum-ii/description/) |[递归+二叉树](Prefix\PathSum专题\lc113.cpp)|


### 9. 基础数据结构


### 10. PrefixSum
| 题     | 笔记 |
| ----------- | ----------- |
|[lc560 和为 K 的子数组](https://leetcode.cn/problems/subarray-sum-equals-k/)|[前缀和+哈希](Prefix\Prefix_Hash\lc560.cpp)|
|[lc974 和可被 K 整除的子数组](https://leetcode.cn/problems/subarray-sums-divisible-by-k/)|[前缀和+哈希+取模](Prefix\Prefix_Hash\lc974.cpp)|
|[lc523 连续的子数组和](https://leetcode.cn/problems/continuous-subarray-sum/)|[前缀和+哈希+取模+长度限制](Prefix\Prefix_Hash\lc523.cpp)|
|[lc525 连续数组](https://leetcode.cn/problems/contiguous-array/)|[前缀和+哈希+取模](Prefix\Prefix_Hash\lc525.cpp)|
|[lc2845 统计趣味子数组的数目](https://leetcode.cn/problems/count-of-interesting-subarrays/description/)|[前缀和+哈希+取模](Prefix\Prefix_Hash\lc2845.cpp)|


### 11. Sort
| 题     | 笔记 |
| ----------- | ----------- |
|[lc207. 课程表](https://leetcode.cn/problems/course-schedule/description/?envType=daily-question&envId=2023-09-09)|[拓扑排序](Sort\topologicSort\lc207.cpp)|
|[lc210 课程表 II](https://leetcode.cn/problems/course-schedule-ii/?envType=daily-question&envId=2023-09-10)|[拓扑排序](Sort\topologicSort\lc210.cpp)|
|[lc1462 课程表 IV](https://leetcode.cn/problems/course-schedule-iv/description/?envType=daily-question&envId=2023-09-12)|[拓扑排序](Sort\topologicSort\lc1462.cpp)|

### 12. BitOperation


### 13. KMP


### 14. Brain Teaser(脑筋急转弯)
| 题     | 笔记 |
| ----------- | ----------- |
|[lc9 回文数](https://leetcode.cn/problems/palindrome-number/)|[:memo:](GoodTrick\lc9.md)|
|[lc2780 合法分割的最小下标](https://leetcode.cn/problems/minimum-index-of-a-valid-split/)|[证明题](GoodTrick\lc2780.md)|
### 15. Mutithread

### 16. 单调队列
| 题     | 笔记 |
| ----------- | ----------- |
|[lc918 环形子数组的最大和](https://leetcode.cn/problems/maximum-sum-circular-subarray/description/)|[单调递增队列](MonotonicQueue\lc918.md)|
|[lc239 滑动窗口最大值](https://leetcode.cn/problems/sliding-window-maximum/)|[模板题](MonotonicQueue\lc239.md)|
|[lc862 和至少为 K 的最短子数组](https://leetcode.cn/problems/shortest-subarray-with-sum-at-least-k/)|[单调递增队列](MonotonicQueue\lc862.md)|
|[lc1499 满足不等式的最大值](https://leetcode.cn/problems/max-value-of-equation/)|[单调递减队列](MonotonicQueue\lc1499.md)|
|[lc2831 找出最长等值子数组](https://leetcode.cn/problems/find-the-longest-equal-subarray/description/)|[双端队列](MonotonicQueue\lc2831.md)|

### 17. 高级数据结构
| 题     | 笔记 |
| ----------- | ----------- |
|[lc2208 将数组和减半的最少操作次数](https://leetcode.cn/problems/minimum-operations-to-halve-array-sum/description/)|[贪心+优先队列](Datastructure\heap_PriorityQueue\lc2208.md)|
||[大顶堆(优先队列)手动实现模板](Datastructure\heap_PriorityQueue\MaxHeap.md)|
||[c++STL优先队列模板](Datastructure\heap_PriorityQueue\cplusplusPQ.md)|
|[lc23 合并 K 个升序链表](https://leetcode.cn/problems/merge-k-sorted-lists/description/)|[优先队列+链表](Datastructure\heap_PriorityQueue\lc23.md)|
|[lc155 最小栈](https://leetcode.cn/problems/min-stack/description/)|[辅助栈](Datastructure\AssistStack\Patten.cpp)|


### 18. 模拟
| 题     | 笔记 |
| ----------- | ----------- |
|[lc722 删除注释](https://leetcode.cn/problems/remove-comments/description/)|[栈模拟](模拟\lc722.md)|
|[lc24 两两交换链表中的节点](https://leetcode.cn/problems/swap-nodes-in-pairs/description/)|[链表模拟](模拟\lc24.md)|

### 19. 哈希
| 题     | 笔记 |
| ----------- | ----------- |
|[lc2834 找出美丽数组的最小和](https://leetcode.cn/problems/find-the-minimum-possible-sum-of-a-beautiful-array/description/)|[哈希+证明](Hash\lc2834.md)|
|[lc1222 可以攻击国王的皇后](https://leetcode.cn/problems/queens-that-can-attack-the-king/description/?envType=daily-question&envId=2023-09-14)|[哈希](Hash\lc1222.cpp)|
|[lc49 字母异位词分组](https://leetcode.cn/problems/group-anagrams/?envType=study-plan-v2&envId=top-100-liked)|[哈希+模拟](Hash\lc49.cpp)|

### 20. 贪心
| 题     | 笔记 |
| ----------- | ----------- |
|[lc1921 消灭怪物的最大数量](https://leetcode.cn/problems/eliminate-maximum-number-of-monsters/?envType=daily-question&envId=2023-09-03)|[贪心+排序](tanxin\lc1921.md)|


### 21. 链表
| 题     | 笔记 |
| ----------- | ----------- |
|[lc21 合并两个有序链表](https://leetcode.cn/problems/merge-two-sorted-lists/description/?envType=study-plan-v2&envId=top-100-liked)|[原地合并链表](Datastructure\LinkedList\lc21.cpp)|
|[lc234 回文链表](https://leetcode.cn/problems/palindrome-linked-list/)|[反转链表+快慢指针](Datastructure\LinkedList\lc234.cpp)|
|[lc19 删除链表的倒数第 N 个结点](https://leetcode.cn/problems/remove-nth-node-from-end-of-list/description/?envType=study-plan-v2&envId=top-100-liked)|[快慢指针](Datastructure\LinkedList\lc19.cpp)|
|[lc138 随机链表的复制](https://leetcode.cn/problems/copy-list-with-random-pointer/?envType=study-plan-v2&envId=top-100-liked)|[哈希+链表](Datastructure\LinkedList\lc138.cpp)|
|[lc148 排序链表](https://leetcode.cn/problems/sort-list/description/?envType=study-plan-v2&envId=top-100-liked)|[快慢指针+归并排序+链表](Datastructure\LinkedList\lc148.cpp)|