class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1)return nums[0];
        else if(nums.size()==2)return max(nums[0], nums[1]);
        int first = nums[0], second = max(nums[1], nums[0]); // second 代表到该下标为止，能够得到的最高金额
        for(int i=2;i<nums.size();i++){
            int tmp = second;
            second = max(second, first+nums[i]);
            first = tmp;
        }
        return second;
    }
};
/*
选或不选思路

dp[i] = max(dp[i-1], dp[i-2]+nums[i])
*/