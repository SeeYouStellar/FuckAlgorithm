>前言：先搞清楚子序列和子串的区别，那就是子序列允许返回的序列在原序列中不连续，子串是原序列的子集，严格要求连续。然后我各给出了两个时间复杂度的方法解决LIS和LCS
## 问题1：最大递增子序列 LIS
1. $O(n^2)$: 

**状态转移方程**如下，使用一维线性DP
$dp[i]=max\{dp[j]|arr[j]<arr[i], 0\le j <i\}+1 , dp[0]=0$ 

**伪代码**如下：
```cpp
int lengthOfLIS(vector<int>& nums) {
    int dp[2501], MAX = 0;
    memset(dp, 0, sizeof(dp));
    for(int i=0;i<nums.size();i++){
        for(int j=i-1;j>=0;j--)
            if(nums[j]<nums[i]) dp[i+1]=max(dp[j+1], dp[i+1]);
        dp[i+1]+=1;
        if(MAX < dp[i+1]) MAX=dp[i+1];
    }
    return MAX;
}
```
2. $O(nlog^n)$

**改进方法**：同样是一次遍历，但不回头找使 $arr[j]<arr[i]$ 成立的元素。建立一个最长递增序列$dp[i]$，代表长度为$i$的最长递增子序列的末尾元素。开始时为空，每搜索一个元素 $arr[i]$，则从后往前遍历 $dp[]$ 序列，若$arr[i]$小于（符合递增要求）$dp[j]$,则继续向前遍历，知道找到一个$dp[j]$小于$arr[i]$，将$dp[j]$替换成$arr[i]$即可。这样的话如果把这个搜索的过程用**二分**，就可以将搜索过程时间复杂度降为$O(log^n)$，最后总的时间复杂度即为$O(nlog^n)$。其实也可以把过程理解为**贪心**，即每遍历一个元素$arr[i]$,就要去用它代替某个$dp[i]$，使长度为$i$的最长递增子序列的末尾元素尽可能小，这样后面的元素比它大的可能性就变大了。

**以下两个c++函数内部用二分搜索实现**，并且他们只相差了一个等于，$cmp$可以是$greater<int>()$也可以是自定义。
```
lower_bound(int* begin, int* end, element, cmp):找到序列中第一个大于等于element的元素指针并返回
upper_bound(int* begin, int* end, element, cmp):找到序列中第一个大于element的元素指针并返回
```
**伪代码**如下：
```cpp
const int maxn = 100010;
int n, dp[maxn], a[maxn];
int lengthOfLIS()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    dp[0] = 0;
    int len = 0;
    for(int i=1;i<=n;i++){
        if(a[i] > dp[len])
            dp[++len] = a[i];
        else *lower_bound(dp, dp + len, a[i]) = a[i];//二分查找比s[i]大的第一个数并替换
    }
    return len;
}
```
## 问题2：最大相同子序列 LCS 
1. $O(n^2)$

**状态转移方程**如下，使用二维线性DP：
$$dp[i][j]=
\begin{cases}
max{dp[i-1][j], dp[i][j-1]}& \text{arr[i]!=arr[j]}\\
dp[i-1][i-1]+1& \text{arr[i]==arr[j]}
\end{cases}$$
**伪代码**如下：
```cpp
int n, a[100010], b[100010], dp[10010][10010];
int lengthofLCS() {
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
        cin>>b[i];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(a[i]==b[j]) dp[i][j] = dp[i-1][j-1]+1;
            else dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
        }
    }
    return dp[n][n];
}
```
2. $O(nlog^n)$：针对两个序列元素相同的情况

**改进方法**：使用和LIS一样的处理方式，只不过运用**离散化**的思想，或者可以理解为**哈希**。首先将序列$a$的每个元素映射成一个递增序列，设想此时若将序列$b$的元素也用相同方法映射，如下如：
```
a: 4 5 3 8 1 -> 1 2 3 4 5 有序
b: 5 3 4 1 8 -> 2 3 1 5 4
```
接下来，有这么一句话肯定是对的，序列$b$中的子序列若和序列$a$相同，那么此时离散化后的序列$b$的子序列必是离散化后序列$a$的子序列。然后这个离散化的子序列还一定有序，因为i序列$a$离散化是有序的，其子序列也一定有序。这样就找到了**离散化后相同子序列**的约束，即只需要找离散化后序列$b$中**最大递增子序列**即可。
**伪代码**如下：
```cpp
const int maxn = 100010;
int n, dp[maxn], a[maxn], b[maxn];
map<int, int> m;
int lengthofLCS()
{
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        m[a[i]] = i;
    }
    for(int i=1;i<=n;i++)
        cin>>b[i];  
    dp[0]=0;
    int len=0; 
    for(int i=1;i<=n;i++){   //找序列b的递增子序列
        if(m[b[i]]>dp[len])
            dp[++len] = m[b[i]];
        else
            *lower_bound(dp, dp+len, m[b[i]]) = m[b[i]];  //找到不小于目标值的第一个元素
    }
    return len;
}
```
>后话：最大递增子串太简单就不介绍了，最大相同子串用kmp算法解决。
## 问题3：最大递增子串 
**状态转移方程**如下，使用一维线性DP：
$$dp[i]=
\begin{cases}
1& \text{arr[i]>arr[j]}\\
dp[i-1]+1& \text{arr[i]<arr[j]}
\end{cases}$$
这里认为相等元素不递增，若是求最大不递减子串，那只需在第二种情况时改为$arr[i]<=arr[j]$