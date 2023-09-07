/*
完全背包问题
完全平方数数组即为物品数组，背包重量为n，物品可以无限次放置

因为有物品1的存在，背包无论如何都会被刚好放满，多出的空间就用多少个1去填就行了。（也就是说，n一定能表示成完全平方数之和，只是多少个完全平方数的区别）

dp[i]代表当背包重量为i且背包被放满时，背包中所能放置的最少的物品数量

*/
class Solution {
public:
    int numSquares(int n) {
        int index = 0;
        int dp[10010] = {0};
        vector<int> x;
        for(int i=1;i<=sqrt(n);i++){
            x.push_back(i*i);
        }
        int res = 0x3f3f3f3f;
        for(int i=0;i<x.size();i++){
            for(int j=x[i];j<=n;j++){
                if(x[i]==1)dp[j]=dp[j-x[i]]+1;
                dp[j] = min(dp[j-x[i]]+1, dp[j]);
            }
        }
        return dp[n];
    }
};

