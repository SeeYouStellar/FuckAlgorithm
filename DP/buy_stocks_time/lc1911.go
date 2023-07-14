/*
一个下标从 0 开始的数组的 交替和 定义为 偶数 下标处元素之 和 减去 奇数 下标处元素之 和 。

比方说，数组 [4,2,5,3] 的交替和为 (4 + 5) - (2 + 3) = 4 。
给你一个数组 nums ，请你返回 nums 中任意子序列的 最大交替和 （子序列的下标 重新 从 0 开始编号）。

一个数组的 子序列 是从原数组中删除一些元素后（也可能一个也不删除）剩余元素不改变顺序组成的数组。比方说，[2,7,4] 是 [4,2,3,7,2,1,4] 的一个子序列（加粗元素），但是 [2,4,2] 不是。


注意：1. 求得是子序列的最大交替和，故子序列的元素个数决定了下一个元素加入时它是位于奇数位还是偶数位
	 2.even[i]代表下标i后下一个是偶数位的子序列，odd代表下标i后下一个是奇数位的子序列
	 3. 每个元素可以选择加入或者不加入，不加入时，该下标处even[i]和odd[i]就与even[i-1]和odd[i-1]相同，并且不会产生奇数位偶数位转换
     加入时，该下标处，even[i]（下一个元素是偶数位）需要odd[i-1]（下一个元素是奇数位）加上nums[i]之后，此时就符合了even[i]的定义

     这道题本质是买卖股票问题
*/

func maxAlternatingSum(nums []int) int64 {
    even := make([]int, len(nums))  // 下一位是偶数位的子序列的最大交替和
    odd := make([]int, len(nums))   // 下一位是奇数位的子序列的最大交替和
    even[0] = nums[0]
    odd[0] = 0
    for i:=1;i<len(nums);i++ {
        even[i] = max(even[i-1], odd[i-1]+nums[i])
        odd[i] = max(odd[i-1], even[i-1]-nums[i])
    }
    return int64(max(even[len(nums)-1], odd[len(nums)-1]))
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}

