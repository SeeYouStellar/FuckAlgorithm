class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int prefix[100010] = {0};
        unordered_map<int, int> m;  // 哈希表：存储前缀和取模后相同的下标个数
        int ret = 0;
        m[0] = 0;
        for(int i=1;i<=nums.size();i++){
            prefix[i] = prefix[i-1]+nums[i-1];
            int x = i-2*prefix[i];
            if(m.count(x)!=0){   // c++ 负数取模仍然是负数，不符合要求，需要经过特殊处理
                if(ret<i-m[x])ret=i-m[x];
            } 
            if(m.count(x)==0)m[x]=i; 
        }
        return ret;
    }
};

// i-j-(prefix[i]-prefix[j]) == prefix[i]-prefix[j]
// i-2preix[i] == j-2prefix[j]