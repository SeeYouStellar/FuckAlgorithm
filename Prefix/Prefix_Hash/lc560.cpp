/**
 * ! 数据不是恒正的，找不到一个单调的序列，所以无法使用滑动窗口（包括双指针、单调队列）的解法去做
 * 
 * * prefix[i]-prefix[j]==k -> prefix[i]==prefix[j]+k
 */
class Solution {
public:
    
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        int prefix = 0, res = 0;
        map[0] = 1;
        for(int i=0;i<nums.size();i++) {
            prefix = prefix+nums[i];
            if(map.count(prefix-k)!=0) {
                res += map[prefix-k];
            }
            map[prefix] ++;
        } 
        return res;
    }
};
