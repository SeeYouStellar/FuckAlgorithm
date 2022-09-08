// 将题目抽象成01背包问题：假设数组元素值之和为sum,令背包容量t为sum/2。每个物品重量和价值相同。问题就变成了从背包中找出某些物品使物品重量为t，且价值也为t。
// 即按正常01背包问题的结构写，只需要每个物品的dp计算完，判断在背包重量为t时，是否价值为t，若有则可以分成两部分。
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int t=0;
        for(int i:nums)t+=i;
        if(t%2==0){
            t/=2;
            int dp[210][10010]={0};
            for(int i=1;i<=nums.size();i++){
                for(int j=1;j<=t;j++){
                    if(nums[i-1]<=j)dp[i][j]=max(dp[i-1][j], dp[i-1][j-nums[i-1]]+nums[i-1]);
                    else dp[i][j]=dp[i-1][j];
                }
                if(dp[i][t]==t)return true;
            }
            return false;
        }else
            return false;
    }
};