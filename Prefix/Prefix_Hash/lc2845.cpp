class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        int a[100010]={0};
        int prefix[100010]={0};
        unordered_map<int, int> m;
        m[0]++;
        long long res = 0;
        for(int i=1;i<=nums.size();i++){
            if(nums[i-1]%modulo==k)a[i-1]=1; //求数组a
            prefix[i] = prefix[i-1]+a[i-1];  //求a的前缀和数组
            int x=(prefix[i]-k)%modulo;
            if(m.count(x)!=0)res+=m[x];
            m[prefix[i]%modulo]++;
        }
        return res;
    }
};

/*
新建一个数组a，长度与nums相同。

把符合nums[i]%modulo==k的下标位置处，a[i]=1,其余为0

此时问题转化成了求a数组中 满足1的个数cnt%modulo==k的子数组 个数

计算数组a的前缀和数组，此时问题变成了遍历i, 求满足(prefix[i]-prefix[j])%modulo==k的j个数

(prefix[i]-prefix[j])%modulo==k 
-> (prefix[i]-prefix[j])%modulo==k%modulo
-> prefix[i]%modulo - prefix[j]%modulo == k%modulo
-> prefix[j]%modulo == prefix[i]%modulo-k%modulo

这样，i和j就形成了关系，在遍历到i时，不需要向前再次遍历来求符合要求的子数组，而是在遍历j时，就通过这种类似未卜先知的方法记录下了prefix[j]%modulo

使用map记录值为prefix[j]%modulo值的下标个数 

这样遍历完i,就更新m[prefix[i]%modulo]++
*/