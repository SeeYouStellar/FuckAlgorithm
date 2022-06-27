## $pattern1$:
最原始的要求：在单调无重复序列中找到目标值的位置，若没有则返回$nums.size()$
```
int binarySearch(vector<int> nums, int target){
    int l = 0;
    int r = nums.size()-1;
    int ans = nums.size();
    while(l <= r){
        int mid = (l+r)/2;
        if(nums[mid] < target){
            l = mid+1;
        }else if(nums[mid] > target){
            r = mid-1;
        }else{
            ans = mid;
            break;
        }
    }
    return ans;
}
```
## $pattern2$:
稍难一点的要求：在单调重复序列中找到第一个目标值的位置，若没有则返回第一个大于目标值的元素位置(也可能都比目标值小则返回超尾)。这其实就是$lower\_bound()$函数的功能
```
int binarySearch(vector<int> nums, int target){
    int l = 0;
    int r = nums.size()-1;
    int ans = -1;
    while(l <= r){
        int mid = (l+r)/2;
        if(nums[mid] < target){
            l = mid+1;
        }else if(nums[mid] >= target){  
            //当遇到第一个目标值时，nums[mid]==target 且 nums[mid-1] < target ，下一次就不会更新ans了
            r = mid-1;
            ans = mid;
        }
    }
    return ans;
}
```
至于为什么可以在没有目标值时返回大于目标值的第一个数。首先具体情况一定是${1,3}$找$2$这种。那么就可以这么想，没有找到目标值的情况只有两种，即此时$l==r$，并且$nums[mid]>target$或$nums[mid] < target $,然后$r-1$或$l+1$后就会产生$l>r$的情况，如果是前者，即此时$nums[mid]==3$,最后一次是进入
```
else if(nums[mid] >= target){  
    //当遇到第一个目标值时，nums[mid]==target 且 nums[mid-1] < target ，下一次就不会更新ans了
    r = mid-1;
    ans = mid;
}
```
那么此时$ans$就符合要求，等于第一个大于目标值元素的下标。如果是后者，$nums[mid]==1$，那么这一次不会再更新ans，而前一次一定是从$nums[mid]==1$这种情况，想想为什么？

## $pattern3$:
另一种要求：在单调重复序列中找到第一个大于目标值的元素位置。即要求实现$upper\_bound()$
```
int binarySearch(vector<int> nums, int target){
    int l = 0;
    int r = nums.size()-1;
    int ans = -1;
    while(l <= r){
        int mid = (l+r)/2;
        if(nums[mid] <= target){
            l = mid+1;
        }else if(nums[mid] > target){  
            r = mid-1;
            ans = mid;
        }
    }
    return ans;
}
```