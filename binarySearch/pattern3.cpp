#include <bits/stdc++.h>
using namespace std;
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
int main(){
    vector<int> ans{1, 2, 2, 3, 3, 6};
    cout<<binarySearch(ans, 5);
    system("pause");
}