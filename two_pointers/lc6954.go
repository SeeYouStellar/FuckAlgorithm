func countPairs(nums []int, target int) int {
    sort.Ints(nums)
    l, r := 0, len(nums)-1
    res := 0
    for l<r {
        if nums[l]+nums[r]<target {
            l++
            res += r-l+1 //代表从l+1都r之间的元素与l元素之和都小于target
        } else {
            r--
        }
    }
    return res
}