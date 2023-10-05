// 把三重循环简化成两重循环
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i=0;i<n;i++){
            if(i>0&&nums[i]==nums[i-1])continue; // 防止重复
            int k = n-1; // 关键
            for(int j=i+1;j<n;j++){
                if(j>i+1&&nums[j]==nums[j-1])continue;  // 防止重复
                if(nums[i]+nums[j]+nums[k]<0) continue; // 这种情况k减小只会使总和更小，所以直接跳过
                while(k>j&&nums[i]+nums[j]+nums[k]>0){
                    k--;
                }
                if(k>j&&nums[i]+nums[j]+nums[k]==0){
                    res.push_back(vector{nums[i], nums[j], nums[k]});
                }
            }
        }
        return res;
    }
};