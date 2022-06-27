### 力扣121

> 题目要求：一只股票，只能买卖一次，那么只有一个买入点和卖出点。且很容易理解，无论如何股票必须卖出时才会得到最大利润，因为假设到最后一天仍不卖出，此时的利润为0，卖出就会得到股票当天的价格。

**思路**：从买者手头现金角度考虑，一开始现金为0，在第$i$天买入一只股票时，现金为$-price[i]$ ，注意这里是负的。那么只需要得到在哪一天卖出的现金**最大**即可。按照这个思路去设计$dp$数组，让$dp[0][i]$代表第$i$天结束未持有股票时最大现金数，$dp[1][i]$代表第$i$天结束仍持有股票时最大现金数。那么状态转移方程为：
$$
\begin{equation}
dp[i]=\begin{cases}
dp[0][i]=max\{dp[0][i-1], dp[1][i-1]+price[i]\} \\
dp[1][i]=max\{dp[1][i-1], -price[i]\}
\end{cases}
\end{equation}
$$



$dp[1][i]$：当假设第$i$天结束手头仍持有股票，那么只有两种情况，第一种为前一天就持有股票，今天仍然持有着；第二种情况就是前一天没有持有股票，今天刚买进。$dp[0][i]$：当假设第$i$天结束手头已经不持有股票了，那么也有两种情况，第一种就是前一天就已经没有持有了；第二种情况就是前一天仍然持有股票，但今天卖出了。

```c++
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if (len == 0) return 0;
        vector<vector<int>> dp(len, vector<int>(2));
        dp[0][1] -= prices[0];
        dp[0][0] = 0;
        for (int i = 1; i < len; i++) {
            dp[i][1] = max(dp[i - 1][1], -prices[i]);
            dp[i][0] = max(dp[i - 1][0], prices[i] + dp[i - 1][1]);
        }
        return dp[len - 1][0];
    }
};
```

### 力扣122

> 题目要求：与前一道题唯一区别，可以买卖多次，即买进卖出后，可以再买进，但不能有加仓行为，即同一时间持有的股票只能是一次买进的。

**思路**：可以延用上一题的$dp[0][i],dp[1][i]$的设定，只是需要稍微改一下$dp[1][i]$的状态转移方程。$dp[1][i]$： 当假设第$i$天结束手头仍持有股票，那么只有两种情况，第一种为前一天就持有股票；第二种为前一天未持有股票，那么今天买进股票，这种情况不再是$-price[i]$，因为在前面可能已经有赚了钱，不再是0现金。
$$
\begin{equation}
dp[i]=\begin{cases}
dp[0][i]=max\{dp[0][i-1], dp[1][i-1]+price[i]\} \\
dp[1][i]=max\{dp[1][i-1], dp[0][i-1]-price[i]\}
\end{cases}
\end{equation}
$$

```c++
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int dp[2][100010];
        dp[0][0] = 0;
        dp[1][0] = -prices[0];
        int n = prices.size();
        for(int i=1;i<n;i++){
            dp[0][i] = max(dp[0][i-1], dp[1][i-1]+prices[i]);
            dp[1][i] = max(dp[1][i-1], dp[0][i-1]-prices[i]);
        }
        return dp[0][n-1];
    }
};
```

