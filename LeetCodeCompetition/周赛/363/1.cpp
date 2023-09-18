/*
给你一个下标从 0 开始的整数数组 nums 和一个整数 k 。

请你用整数形式返回 nums 中的特定元素之 和 ，这些特定元素满足：其对应下标的二进制表示中恰存在 k 个置位。

整数的二进制表示中的 1 就是这个整数的 置位 。

例如，21 的二进制表示为 10101 ，其中有 3 个置位。
*/
class Solution {
public:
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int dp[1010] = {0};
        
        int res = 0;
        dp[0] = 0;
        if(k==0)res+=nums[0];
        dp[1] = 1;
        if(k==1)res+=nums[1];
        int last2 = -1;
        for(int i=2;i<nums.size();i*=2){
            dp[i]=1;
        }
        for(int i=2;i<nums.size();i++){
            if(dp[i]==1){
                last2 = i;
            }else{
                dp[i] = dp[last2]+dp[i-last2];
            }
            if(dp[i]==k){
                res+=nums[i];
            }
        }
        return res;
    }
};