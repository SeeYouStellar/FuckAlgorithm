/*6899. 达到末尾下标所需的最大跳跃次数
给你一个下标从 0 开始、由 n 个整数组成的数组 nums 和一个整数 target 。

你的初始位置在下标 0 。在一步操作中，你可以从下标 i 跳跃到任意满足下述条件的下标 j ：

0 <= i < j < n
-target <= nums[j] - nums[i] <= target
返回到达下标 n - 1 处所需的 最大跳跃次数 。

如果无法到达下标 n - 1 ，返回 -1 。

*/
func maximumJumps(nums []int, target int) int {
    dp := make([]int, 0)
    dp = append(dp, 0)
    for i:=1;i<len(nums);i++ {
        maxStepCount := 0
        for j:=i-1;j>=0;j-- {
            if cmp(nums[i]-nums[j], target)==true && dp[j]!=-1 && maxStepCount < dp[j]+1{
                maxStepCount = dp[j]+1
            }
        }
        if maxStepCount!=0 {
            dp = append(dp, maxStepCount)
        } else {
            dp = append(dp, -1)
        }
        // fmt.Println(dp[i])
    }
    return dp[len(nums)-1]
}

func cmp(x int ,y int) bool {
    if x <= y && x >= y*-1 {
        return true
    } else {
        return false
    }
}