/*
完全背包问题

求最小

*/
class Solution {
public:
    int numSquares(int n) {
        int MAX = n+1;   
        vector<int> dp(n+1, MAX);   // 关键：因为1是完全平方数，n肯定能被n个1组合得到，所以最大数量为n，用MAX=n+1表示不存在
        dp[0] = 0;
        for(int i=1;i<=sqrt(n);i++){
            int x = i*i;
            for(int j=x;j<=n;j++){
                dp[j] = min(dp[j-x]+1, dp[j]);  
            }
        }
        return dp[n];
    }
};

