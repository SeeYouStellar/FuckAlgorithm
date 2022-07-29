

### [剑指 Offer 60. n个骰子的点数](https://leetcode.cn/problems/nge-tou-zi-de-dian-shu-lcof/)

> 题目意思就是要找每个点数出现的次数，本题最多的骰子数为11，若是用遍历、递归等方式时间复杂度在$O(11^{11})$很显然不行。那么主要原因是会产生重复计算，比如说要计算三个骰子值为4的次数，那么很自然是2个骰子抛出3，1个骰子抛出1情况的次数加上2个骰子抛出2，1个骰子抛出2情况的次数，可以看出，在计算2个骰子抛出3情况的次数时，肯定包括了1个骰子抛出2和1个骰子抛出1这两种情况。

**思路：**想要减少重复计算，那么动态规划是理想的，并且一定是二维的。

1. 给出$dp[i][j]$的定义，$dp[i][j]$，$i$表示$i$个骰子，$j$表示点数和为$j$，$dp[i][j]$表示当有$i$个骰子时，点数和为$j$情况的点数。

2. 给出状态转移方程
   $$
   dp[i][j] = \sum_{k=1}^j dp[i-1][j-k]*dp[1][k]
   $$

3. 初始状态：
   $$
   dp[i][0] = 0\\
   dp[o][i] = 0\\
   dp[1][i] = 1
   $$
   

```c++
class Solution {
public:
    vector<double> dicesProbability(int n) {
        int dp[12][12*12] = {0};
        int cnt = 0;
        for(int i=1;i<=6;i++){dp[1][i]=1;if(1==n)cnt+=dp[1][i];}
        for(int i=2;i<=n;i++){
            for(int j=i;j<=i*6;j++){
                for(int k=1;k<=j;k++){
                    dp[i][j] += dp[i-1][j-k]*dp[1][k];
                }
                if(i==n)cnt+=dp[i][j];
            }
        }
        // cout<<cnt<<endl;
        // for(int i=n;i<=n*6;i++) cout<<dp[n][i]<<" ";
        vector<double> ans; 
        for(int i=n;i<=n*6;i++) ans.push_back(dp[n][i]*1.0/cnt);
        return ans;
    }
};
```

