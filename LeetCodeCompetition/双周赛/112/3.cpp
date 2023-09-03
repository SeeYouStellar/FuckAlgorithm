class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {
       
        map<int, int> mp;
        int cnt = 0;
        long long sum = 0;
        long long res = 0;
        for(int i=0;i<k;i++){
            if(mp.count(nums[i])==0){
                cnt++;
            }
            mp[nums[i]]++;
            sum+=nums[i];
        }
        if(mp.size()>=m){
            res=sum;
        }
        for(int i=k;i<nums.size();i++){
            if(mp.count(nums[i])==0){
                cnt++;
            }
            mp[nums[i]]++;
            sum+=nums[i];
            mp[nums[i-k]]--;
            if(mp[nums[i-k]]==0){
                cnt--;
                mp.erase(nums[i-k]);
            }
            sum-=nums[i-k];
            
            if(mp.size()<m){
                continue;
            }
            if(sum>res)res=sum;
        }
        return res;
    }
};