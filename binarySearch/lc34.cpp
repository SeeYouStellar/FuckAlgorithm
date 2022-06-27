class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int begin = lower_bound(nums.begin(), nums.end(), target)-nums.begin(); //找到第一个大于等于目标值的元素下标
        int end = upper_bound(nums.begin(), nums.end(), target)-nums.begin();  //找到第一个大于目标值的元素位置
        if(begin==nums.size() || nums[begin]!=target){
            return vector<int>{-1, -1};
        }else{
            return vector<int>{begin, end-1};
        }
    }
};