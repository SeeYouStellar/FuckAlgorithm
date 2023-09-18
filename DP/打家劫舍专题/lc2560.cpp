class Solution {
public:
    int getdp(vector<int>& nums, int mx){
        vector<int> dp(nums.size()+10, 0);
        dp[0] = nums[0]<=mx?1:0;
        dp[1] = nums[1]<=mx?max(dp[0], 1):dp[0];
        for(int i=2;i<nums.size();i++){
            dp[i] = nums[i]<=mx?max(dp[i-1], dp[i-2]+1):dp[i-1];
        }
        return dp[nums.size()-1];
    }
    int minCapability(vector<int>& nums, int k) {
        if(nums.size()==1)return nums[0];
        int l = 0x3f3f3f3f, r = -0x3f3f3f3f;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<l)l=nums[i];
            if(nums[i]>r)r=nums[i];
        }
        while(l<=r){
            int mid = (l+r)>>1;
            if(k>getdp(nums, mid)){
                l = mid+1;
            }else{
                r = mid-1;
            }
        }
        return l;
    }
};

/*
最小化最大值问题

假设题目所求的值为ans，ans满足 min(nums[i]) <= ans <= max(nums[i])

观察可得：题目所求的子序列中窃取能力ans越大，所窃取的房间数目k越大；反之更小。

此时求满足最大窃取能力为ans，最大不连续序列长度n。为dp问题，dp条件是不能连续并且只能选金额小于等于ans的房间。

每次求出一个n，比较n与k的关系，n>=k,则ans只可能更小；反之更大。这是一个二分的过程。
*/ 