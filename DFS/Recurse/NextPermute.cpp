// lc31 lc556
// 实现stl函数next_permution(iterator first, iterator last, cmp)
// 该函数可作用与vector, string, 并且是原地操作，返回值代表是否有下一个序列
/*
vector<char> chars = {'a', 'b', 'c'};
  do {
    cout << chars[0] << chars[1] << chars[2] << endl;
  } while (next_permutation(chars.begin(), chars.end()));
*/
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
    // 要想获得一个大于当前排列的数，那么必定是从排列后方选一个数，从前方选一个数，后方的数要比前方的数大
    // 这个前方的数的所在位要尽可能低，后方的数要尽可能小
    // 1. 先从最低位开始找到一个降序序列，找到后降序序列前一位数即为最低位的可交换的小数，因为降序序列里前方数永远大于后方的数，交换后只会变更小
    // 2. 找到前方小数后，就需要找后方大数，这个数尽可能接近小数，那么就从后往前遍历降序序列即可，找到大于前方小数的最小数
    // 3. 交换后的前方小数位上已经是大数了，那么这一位已经决定了整个数大于原序列了，那么为了找到最接近原序列的序列，把后方序列升序排列即可 
        int n = nums.size();
        int i=n-1;
        while(i-1>=0 && nums[i]<=nums[i-1])i--;    
        if(i-1>=0){ 
            int j=n-1;
            while(j>i-1 && nums[j]<=nums[i-1])j--;
            swap(nums[j], nums[i-1]);
        }
        // 原序列已经是降序序列，那么下一个序列就是最小序列
        for(int j=i,k=n-1;j<k;j++,k--)swap(nums[j], nums[k]);
    }
};