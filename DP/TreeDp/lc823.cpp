/*
823. 带因子的二叉树

给出一个含有不重复整数元素的数组 arr ，每个整数 arr[i] 均大于 1。

用这些整数来构建二叉树，每个整数可以使用任意次数。其中：每个非叶结点的值应等于它的两个子结点的值的乘积。

满足条件的二叉树一共有多少个？答案可能很大，返回 对 109 + 7 取余 的结果。

注意：只有一个根节点的情况也算

思路：排序+树形DP+哈希表

将数组排序后，将数值从小到大依次作为根节点，计算完小数值作为根节点后的子树个数，后续的大数值作为根节点时就可以使用前面计算好的值

dp[i]代表以i为根节点可以形成的符合条件的树的个数

dp[i]=1+所有dp[j]*dp[i/j], 这里的j满足 i%j==0 且 dp[j]>=0 且 dp[i/j]>=0

*/

class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        unordered_map<int,long long> hashmap;
        sort(arr.begin(), arr.end());
        int res = 0;
        for(int i=0;i<arr.size();i++){
            hashmap[arr[i]]=1;
            for(int j=1;j<sqrt(arr[i])+1;j++){
                if(arr[i]%j==0 && hashmap[j]>=1 && hashmap[arr[i]/j]>=1 && j<=arr[i]/j){ // j<=arr[i]/j 防止重复计算
                    printf("%d %d\n", arr[i]/j, j);
                    hashmap[arr[i]] = (hashmap[arr[i]]+(hashmap[j]*hashmap[arr[i]/j])%(long long)(1e9+7))%(long long)(1e9+7);
                    if((arr[i]/j)!=j)
                        hashmap[arr[i]] = (hashmap[arr[i]]+(hashmap[j]*hashmap[arr[i]/j])%(long long)(1e9+7))%(long long)(1e9+7);
                }
            }
            res=(res+hashmap[arr[i]]%(long long)(1e9+7))%(long long)(1e9+7);
        }
        return res;
    }
};