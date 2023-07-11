/*
这里有一个非负整数数组 arr，你最开始位于该数组的起始下标 start 处。当你位于下标 i 处时，你可以跳到 i + arr[i] 或者 i - arr[i]。

请你判断自己是否能够跳到对应元素值为 0 的 任一 下标处。

注意，不管是什么情况下，你都无法跳到数组之外。

dfs 和 bfs都可以做


重复遍历为何就可以返回false,因为如果上一次遍历找到了0元素
那么如果上一次返回true，假设上一次是在左树分支遍历到,那么左树返回true,不管右树是否会重复遍历到该元素（返回false），两者||之后还是true
如果上一次返回的是false,很明显再次遍历到的时候肯定是false
意思是说不管在哪重复遍历到，返回值都不会影响整个dfs的最终返回值（||的特性）
*/
func canReach(arr []int, start int) bool {
    vis := make([]bool, len(arr))
    return dfs(arr, vis, start)
}

func dfs(arr []int, vis []bool, start int) bool {
    if vis[start] == true { // 开始重复遍历就说明上次遍历到时返回的是false,如果返回的是true，那么自然就已经把true传递到最顶层了
        return false
    }
    if arr[start] == 0 {
        return true
    }
    vis[start] = true
    var a, b bool
    if start-arr[start] >= 0 {  // 左树
        a = dfs(arr, vis, start-arr[start])
    } 
    if start+arr[start] <= len(arr)-1 {   // 右树
        b = dfs(arr, vis, start+arr[start])
    }
    return  a || b
}