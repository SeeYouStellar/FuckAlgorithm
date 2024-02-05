### [剑指 Offer 56 - I. 数组中数字出现的次数](https://leetcode.cn/problems/shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-lcof/)

> 一组数如果只有一个数字是单独出现，而其他数字都是成对出现，那么整个数组异或的结果就是那个单独出现的数字

**异或运算：**

$x_i=x_0 \bigoplus x_1 \bigoplus x_2 \bigoplus x_3 \bigoplus x_i$

其中$x_0,x_1$和$x1,x_2$相同

**问题：**

但题目中是有两个出现一次的数字，那么需要将数组分成两个子数组，这两个子数组都只有一个出现一次的数

$x_i \bigoplus x_j = x_0 \bigoplus x_1 \bigoplus x_2 \bigoplus x_3 \bigoplus x_i \bigoplus x_j$

如果$x_i,x_j$不同那么$x_i \bigoplus x_j $肯定是不为0的数

**那么怎么分数组？**

1. 两个相同的数分到同一组
2. 两个不同的数分到不同组

那么实际如何操作才能做到这样分数组呢？我们已经知道$x_i \bigoplus x_j $是不为0的数，那么其二进制表示时必有某些位不是0，也就说明$x_i,x_j $的这一位不同，一个为1，一个为0。

所以我们可以找到第一个不为0的位，**按该位为1或为0将数组分为两组**。为什么这样可行，即可将两个数组刚好分成只有一个成单数字的子数组？首先成对数字的这一位肯定相同，也就肯定分到了同一组；两个成单数字该位肯定不同，分到了不同组。

不用去管成对的数具体分到哪一组，因为只要保证成对的数在同一组即可。

接下来如何找到$x_i \bigoplus x_j $中为1的位，这里我们就从第1位开始找，找到第一个1即可。

答案是**与运算**。
$$
a=0001, a\&0001=1!=0, 第一位为1\\
a=0010, a\&0010=2!=0, 第二位为1\\
...
$$
用位运算控制二进制数0001循环左移即可。

```c++
class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int n=nums.size();
        int xixj = nums[0];
        int i;
        // 计算xi异或xj
        for(i=1;i<n;i++){
            xixj ^= nums[i];
        }
        int a=1;
        // 找到xixj中第一个不为0的位
        for(i=0;i<n;i++){
            if((xixj&a)!=0)break;
            a = a<<1;
        }
        int xi = 0, xj = 0;
        // 按位分数组
        for(i=0;i<n;i++){
            if((nums[i]&a)==0)xi^=nums[i];
            else xj^=nums[i];
        }
        return {xi, xj};
    }
};
```

### [剑指 Offer 56 - II. 数组中数字出现的次数 II](https://leetcode.cn/problems/shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-ii-lcof/)

> 三个为一对，找出唯一一个单独的数字

**思路：**把所有数字的每一位加起来对3求余即为单独的数字

```c++
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int count[32] = {0};  // 记录int32每一位的和
        int n = nums.size();
        // 计算所有数的每位和
        for(int i=0;i<n;i++){
            for(int j=31;j>=0;j--){
                count[j]+=nums[i]&1;
                nums[i]>>=1;
            }
        }
        // 每位对3求余
        for(int i=0;i<32;i++){
            count[i]%=3;
        }
        int res = 0;
        long tmp = 1;
        // 将二进制转为10进制
        for(int j=31;j>=0;j--){
            res+=count[j]*tmp;
            tmp<<=1;
        }
        return res;
    }
};
```

