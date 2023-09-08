
/*

完全背包问题

求最小

*/
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int Max = amount + 1;
        vector<int> dp(amount + 1, Max);
        dp[0] = 0;
        for(int i=0;i<coins.size();i++){
            for(int j=coins[i];j<=amount;j++){
                dp[j] = min(dp[j], dp[j-coins[i]]+1);
            }
        }
        return dp[amount]>=Max?-1:dp[amount];
    }
};

