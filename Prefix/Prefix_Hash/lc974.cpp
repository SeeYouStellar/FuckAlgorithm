class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int prefix[30010] = {0};
        unordered_map<int, int> m;  // 哈希表：存储前缀和取模后相同的下标个数
        int ret = 0;
        m[0]++;
        int maxPrefix=0, minPrefix=0;
        for(int i=1;i<=nums.size();i++){
            prefix[i] = prefix[i-1]+nums[i-1];
            
            if(m.count((prefix[i]%k+k)%k)!=0){   // c++ 负数取模仍然是负数，不符合要求，需要经过特殊处理
                ret+=m[(prefix[i]%k+k)%k];
            } 
            m[(prefix[i]%k+k)%k]++; 
        }
        return ret;
    }
};

// (prefix[i]-prefix[j])%k==0  ->  prefix[i]%k == prefix[j]%k

// -1 % 4 == 3 正确 ，但是在c++中会求出-1，所以需要(x%k+k)%k处理