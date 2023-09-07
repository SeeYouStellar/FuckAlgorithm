/*
将题目抽象成01背包问题：假设数组元素值之和为sum,令背包容量t为sum/2。每个物品重量和价值相同。问题就变成了从背包中找出某些物品使物品重量为t，且价值也为t。

常规的01背包问题：

dp[i][j] = max(dp[i-1][j], dp[i][j-w[i]]+v[i])

因为实际遍历到某一个物品i时，dp[i][j]的推算只跟上一个物品的dp值（dp[i-1][]）有关，而再往前的dp值其实没有用到，故将物品这个维度去掉

数组压缩：将代表第几个物品的维度消去 -> 需要从大到小遍历背包重量，防止在当前物品计算出的dp值被覆盖


*/
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int bagWeight = 0;
        for(int i=0;i<nums.size();i++) bagWeight+=nums[i];
        if(bagWeight%2!=0){
            return false;
        }
        bagWeight/=2;
        int dp[20010] = {0}; // dp[i]代表当背包重量为i时，背包内的物品总价值
        int n = nums.size(); // 物品个数
        for(int i=1;i<=n;i++){
            for(int j=bagWeight;j>=nums[i-1];j--){  // j<nums[i-1]时放不下物品i了，故与上一次外层循环得到的dp[j]相同
                dp[j]=max(dp[j], dp[j-nums[i-1]]+nums[i-1]);
            }
            if(dp[bagWeight]==bagWeight) return true;  
        }
        return false;
    }  
};

