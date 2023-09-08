class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < coins.size(); i++) { // 遍历物品
            for (int j = coins[i]; j <= amount; j++) { // 遍历背包
                dp[j] += dp[j - coins[i]];
            }
        }
        
        return dp[amount];
    }
};

/*

完全背包问题

求最大

dp[j] 代表当总金额为i时，有dp[i]种金币组合

dp[j] = dp[j]+dp[j-coins[i]]

前者代表总金额为j，没有当前这种金币面额时（只有前几种金币面额），有dp[j]种金币组合。可能为0，代表无法刚好组合到金额j。
后者代表当再次取一个当前这种金币面额时，要想金币总面额为j，则需要知道当金币面额为j-coins[i]时的组合数，如果dp[j-coins[i]]=0，说明此时无法组合;如果不为0，说明加上当前这枚金币后存在金币组合使得总金额为j。

*/