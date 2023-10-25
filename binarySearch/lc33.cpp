class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;
        int indx;
        // ! 寻找旋转点indx，旋转点满足条件nums[mid]<nums[mid-1] && nums[mid]<nums[mid+1]
        // 1. 旋转点把原数组分成了左右两个部分，左边子数组所有数都大于右边子数组所有数
        // 2. 通过判断新数组最后一个元素和nums[mid]的关系，判断此时mid在旋转点indx的左侧还是右侧
        // 3. 若nums[mid]>nums[nums.size()-1]，说明mid在旋转点右侧
        // 3. 若nums[mid]<nums[nums.size()-1]，说明mid在旋转点左侧
        while(l<=r) {
            int mid = (l+r)>>1;
            cout<<mid<<endl;
            // ! 这里把所有退出的情况列出来了，实际上可以把这个分支放在else中。边界条件比较多，包括旋转点是原数组的第一个元素或最后一个元素。
            if((mid-1<0 && mid+1>nums.size()-1) ||(mid-1>=0 && nums[mid]<nums[mid-1] && mid+1<=nums.size()-1 && nums[mid]<nums[mid+1]) || (mid-1<0 && nums[mid]<nums[mid+1]) || (mid+1>nums.size()-1 && nums[mid]<nums[mid-1])) {
                indx = mid;
                break;
            } else if(nums[mid]>nums[nums.size()-1]){  
                l = mid+1; 
            } else if(nums[mid]<nums[nums.size()-1]){
                r = mid-1;
            }
            
        }
        if(target == nums[nums.size()-1]) return nums.size()-1;
        if(target < nums[nums.size()-1]) {
            for(int i=indx;i<nums.size();i++) {
                if(nums[i]==target) {
                    return i;
                }
            }
        } else {
            for(int i=indx;i>=0;i--) {
                if(nums[i]==target) {
                    return i;
                }
            }
        }
        return -1;
    } 
};

