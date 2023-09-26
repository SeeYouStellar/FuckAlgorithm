class Solution {
public:
    /**
     * check(mx):从后往前遍历数组，判断mx是否可以成为数组的最大值
     * 初始状态：
     * i = nums.size()-1
     * now = nums[i]
     * 
     * 每次遍历：
     * 先 pre = nums[i-1]
     * 再判断 now>mx ，要把多出来的值加到pre上。（满足题目要求后减一前加一的原则）
     * 最后向前移动now = pre
     * 
     * 当now移动到数组首元素时，首元素若还是大于mx，因为前面没有元素了，就无法再减了。
     * 所以判断now>mx，若为true，则说明这个最大值mx太大
     * 若为false，则说明这个最大值可行
     */
    bool check(vector<int> nums, int mx) {
        int i = nums.size()-1;
        long now = nums[i], pre;
        i--;
        while(i>=0){
            pre = nums[i--];
            if(now>mx){
                pre += now-mx;
            }
            now = pre;
        }
        if(now>mx)return false;
        return true;
    }
    int minimizeArrayValue(vector<int>& nums) {
        if(nums.size()==1)return nums[0];
        int l = 0x3f3f3f3f, r = -0x3f3f3f3f;
        for(int i=0;i<nums.size();i++){
            if(l>nums[i]) l = nums[i];
            if(r<nums[i]) r = nums[i];
        }
        while(l<=r){
            int mid = (l+r)>>1;
            if(check(nums, mid)){
                r = mid-1;
            }else{
                l = mid+1;
            }
        }
        return l;
    } 
};