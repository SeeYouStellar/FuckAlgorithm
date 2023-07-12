/*
求最大连续子数组和，很经典的题
dp[i]代表以i处元素结尾的子数组的最大和
dp[i] = max(dp[i-1]+nums[i], nums[i])
*/
func maxSubArray(nums []int) int {
    // 注意子数组和子序列和的区别：子序列不要求连续
    dp := make([]int, len(nums))
    dp[0] = nums[0]
    ret := dp[0]
    for i:=1;i<len(nums);i++ {
        if dp[i-1]+nums[i] > nums[i] {
            dp[i] = dp[i-1]+nums[i]
        } else {
            dp[i] = nums[i]
        }
        if dp[i] > ret {
            ret = dp[i]
        }
    }
    return ret
}