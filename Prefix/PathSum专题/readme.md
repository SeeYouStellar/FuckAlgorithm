### lc [437. 路径总和 III](https://leetcode.cn/problems/path-sum-iii/)

> 求二叉树中任意两点的路径总和为$target$的路径条数，两点得符合其中一个点一定要是另一个点的祖先节点

**思路：**题目设定的条件是祖先节点和子节点，那么这两个节点一定是在二叉树的同一条路径上，使用前缀和的思想，先序遍历二叉树，沿途记录每个节点的前缀和。每当访问到某个节点时，假设其前缀和为$prefix_{son}$查找在该点之前的祖先节点中，是否有$prefix_{ancester}$使得$prefix_{son}-prefix_{ancester}==target$成立，若存在这样的祖先节点，那么祖先节点的最近子节点到当前节点之间的路径和一定是$target$。

接下来要解决的问题是：

1. **如何保存前缀和，使得查找祖先前缀和的时间复杂度尽量低？**

   因为要保存沿途的所有前缀和，故需要使用数据结构，而不能是通过传参的方式记录，那么选$unordered\_map$查找的时间复杂度为$O(1)$最好。下表给出$unordered\_map$和$map$的时间复杂度。

   | STL              | 实现   | 各操作时间复杂度 |
   | :--------------- | :----- | ---------------- |
   | $map$            | 红黑树 | $O(\log_{n})$    |
   | $unordered\_map$ | 哈希表 | $O(1)$           |

   那么如何存前缀和呢，自然是用$unordered\_map$的$key$存前缀和，用$value$存这个拥有相同前缀和的节点数。

2. **如何计算符合要求的路径总数？**

   **思路**已经说明了每访问到一个点时，要与该节点的祖先节点产生联系，那么就一定是**先序遍历**。但是要注意的是，每当访问到一个节点时，要更新$unordered\_map$，使该前缀和的节点数+1，使得其子孙节点也能查找；接着，每当访问完一个节点包括其子树后，即要返会父节点时，要将$unordered\_map$更新回来。因为规定了两个节点必须是自上而下的同一条路径上，而不能是分别在两个子树上的。

```c++
class Solution {
public:
    int cnt;
    unordered_map<long, int> map;
    void dfs(TreeNode* root, int& targetSum, long nowSum) {
        if(!root) return ;
        nowSum += root->val;
        if(map.count(nowSum-targetSum)) cnt+=map[nowSum-targetSum];
        map[nowSum]++;
        dfs(root->left, targetSum, nowSum);
        dfs(root->right, targetSum, nowSum); 
        map[nowSum]--;
    }
    int pathSum(TreeNode* root, int targetSum) {
        map[0]=1;  
        /* 
        另外这里也是一个点：
        因为祖先节点和当前节点前缀和之差为targetSum时代表祖先节点的子节点到当前节点的路径和为targetSum，而没有把祖先节点本身算进去。故设一个根节点的		    父节点，其只有根节点一个子节点。其前缀和为0。
        */
        dfs(root, targetSum, 0);
        return cnt;
    }
};
```



### lc [209. 长度最小的子数组](https://leetcode.cn/problems/minimum-size-subarray-sum/)

> 求符合两节点前缀和只差大于等于$target$的**最短连续子数组**，为基本的前缀和问题，只是题目要求时间复杂度在$O(n\log_n)$

**思路1：**与上一题的思路一致，创建一个$prefix$数组，然后遍历每个下标，假设遍历到$prefix[i]$，再向前搜索数组，找到符合下式的下标最大的节点，然后更新最短长度即可。
$$
prefix[i] - prefix[j] >= target\\j\in[0, i)
$$
**首先**要注意的是$prefix[0]=0$是前缀和问题的比较常见的设定（当遇到要两个前缀和相减时），与上题一致**注意**。

**另外**这里的$j$的下标是从0到$i$的左闭右开区间。能取到0是可以理解的，取不到$i$是因为不需要，因为当$j$取到$i-1$时，自然就能照顾到子数组只有元素$i$的情况

时间复杂度：遍历数组每个元素为$O(n)$，每遍历到一个点就向前搜索为$O(n)$，故总复杂度为$O(n^2)$

那么很明显，这种思路下向前搜索的时间复杂度无法减小，那么有没有可能向后搜索呢，这样就可以借助$stl$。

**思路2：**同样的，创建一个$prefix$数组，然后遍历每个下标，既然要向后搜索，那么就要查找符合$prefix[i]+target==prefix[j]$的$j$。自然想到用二分搜索，$lower\_bound(起始位置，结束位置，目标值)：查找大于等于目标值的索引$。

```c++
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        int ans = INT_MAX;
        vector<int> sums(n + 1, 0); 
        // 为了方便计算，令 size = n + 1 
        // sums[0] = 0 意味着前 0 个元素的前缀和为 0
        for (int i = 1; i <= n; i++) {
            sums[i] = sums[i - 1] + nums[i - 1];
        }
        for (int i = 1; i <= n; i++) {
            int target = s + sums[i - 1];
            auto bound = lower_bound(sums.begin(), sums.end(), target);  //这里起始位置用sums.begin()方便，如果要精确到sums.begin()+i-1也行，对时间复杂度不产生影响
            if (bound != sums.end()) {
                ans = min(ans, static_cast<int>((bound - sums.begin()) - (i - 1))); //注意这里不能直接相减
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};
```



时间复杂度：$O(n\log_n)$

当然用滑动窗口做，时间复杂度可以更低。

### lc [238. 除自身以外数组的乘积](https://leetcode.cn/problems/product-of-array-except-self/)

### lc [523. 连续的子数组和](https://leetcode.cn/problems/continuous-subarray-sum/)

**思路：**两数相减是$k$的倍数，那么这两个数也是$k$的倍数。那么就简单了，把前缀和数组求出来，然后用$map$存储每个$prefix[i]\%k$的最大下标。然后遍历前缀和数组，查找与当前下标的$prefix[i]\%k$相同的最大下标$j$，两者相减大于等于2即可返回$true$。

这里要注意的是，既然只需要查找到一组即可返回$true$，那么就尽量在查找时$j$尽量大。在算$prefix[i]$时按序更新就可以使$map[x]$存的下标是余数为$x$的最大下标。

```c++
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int* sum = new int[n + 1];
        sum[0] = 0;
        unordered_map<int, int> map;
        for (int i = 1; i <= n; i++) {
            sum[i] = sum[i - 1] + nums[i - 1];
            map[sum[i]%k] = i;   // 更新map
        }
        for(int i=0;i<=n;i++){
            int j = map[sum[i]%k];   // 查找
            if(j-i>=2) return true;
        }
        delete[] sum;
        return false;
    }
};
```

### lc [525. 连续数组](https://leetcode.cn/problems/contiguous-array/)

**思路：**前缀和数组用来表示到当前下标为止，数组所含1的个数，那么$i-prefix[i]$就是0的个数。子数组的1和0个数相同，其实就是两个下标处1的个数和0的个数之差相同，思路与上一题基本相同。

```c++
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int prefix[100010] = {0};
        unordered_map<int, int> map;
        map[0] = 0;
        for(int i=1;i<=nums.size();i++){
            prefix[i] = prefix[i-1]+(nums[i-1]==1?1:0);
            map[prefix[i]-(i-prefix[i])]=i;   // 1的个数-0的个数
        }
        int l = 0;
        for(int i=0;i<=nums.size();i++){
            int j = map[prefix[i]-(i-prefix[i])];
            if(j-i>l) l=j-i;
        }
        return l;
    }
};
```

### lc [560. 和为 K 的子数组](https://leetcode.cn/problems/subarray-sum-equals-k/)

> 与lc 437的思路一致，因为本题需要给出子数组个数，而不是简单找到一个满足条件的子数组即可。所以涉及到数组的个数问题时，单纯的想法是，遍历$i,j$找到使得$prefix[i]+k==prefix[j]$成立的每个$i,j$。显而易见时间复杂度为$O(n^2)$。这里我们的目标仍然是$O(n)$。

**思路：**既然与lc437思路一致，那么自然要用到$map$储存前缀和个数信息。这里就涉及到存的个数是当前访问的节点之前的前缀和个数还是之后的前缀和个数，如果是之后的，那么从前往后访问到当前节点时，明显无法得到后面节点的前缀和情况，故使用前者。即$map[x]$储存的是当前节点之前，前缀和为$x$的所有下标个数，因为是从前向后遍历，故每访问完一个节点，就更新$map$。

```c++
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        int prefix[20010] = {0};
        for(int i=1;i<=n;i++)
            prefix[i] = nums[i-1]+prefix[i-1];
        int cnt = 0;
        unordered_map<int, int> map;
        map[0] = 1;   // 关键：在lc437已经讲过作用
        for(int i=1;i<=n;i++){
            cnt+=map[prefix[i]-k];
            // gegn'x
            if(map.count(prefix[i])) map[prefix[i]]++;
            else map[prefix[i]] = 1;
        }
        return cnt;
    }
};
```

