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

class Solution2 {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size()==0) return vector{-1, -1};
        // 第一个大于等于target的数
        int l = 0, r = nums.size()-1;
        while(l<=r) {
            int mid = (l+r)>>1;
            if(nums[mid]>=target) {
                r = mid-1;
            } else {
                l = mid+1;
            }
        }
        // 不存在大于等于target的数、不存在小于target的数
        if(l>=nums.size() || (l==0 && nums[l]!=target)) return vector{-1, -1};
        // 没有找到target
        if(nums[l]!=target) return vector{-1, -1};
        int ll = l;
        l = 0;
        r = nums.size()-1;
        // 第一个大于target的数
        while(l<=r) {
            int mid = (l+r)>>1;
            if(nums[mid]>target) {
                r = mid-1;
            } else {
                l = mid+1;
            }
        }
        // 不存在大于target的数
        if(l>=nums.size()) return vector{ll, l-1};

        return vector{ll, l-1};
    }
};