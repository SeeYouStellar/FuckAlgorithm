class Solution {
public:
    int robRange(vector<int>& nums, int start, int end) {
        int dp[110] = {0};
        
        dp[start] = nums[start];
        dp[start+1] = max(dp[start], nums[start+1]);
        for(int i=start+2;i<=end;i++){
            dp[i] = max(dp[i-1], dp[i-2]+nums[i]);
        }
        return dp[end];
    }

    int rob(vector<int>& nums) {
        int length = nums.size();
        if (length == 1) {
            return nums[0];
        } else if (length == 2) {
            return max(nums[0], nums[1]);
        }
        return max(robRange(nums, 0, length - 2), robRange(nums, 1, length - 1));
    }
};

/*
打家劫舍2

如果没有环形这个设置，那么采用经典的选或不选思路，状态转换方程是：dp[i]=max(dp[i-1], dp[i-2]+nums[i])，dp[n]即为最大值

加上环形这个设置时，第一家和最后一家无法同时选择，那么只需要分别算没有第一家和没有最后一家的情况下的最大值即可。
*/