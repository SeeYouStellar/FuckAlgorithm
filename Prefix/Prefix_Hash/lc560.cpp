class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int prefix[20010] = {0};
        unordered_map<int, int> m;  // 哈希表：存储前缀和为key的下标个数
        int ret = 0;
        m[0]++;
        for(int i=1;i<=nums.size();i++){
            prefix[i] = prefix[i-1]+nums[i-1];
            
            if(m.count(prefix[i]-k)!=0){
                ret+=m[prefix[i]-k];
            }
            m[prefix[i]]++; 
        }
        return ret;
    }
};

// prefix[i]-prefix[j]==k -> prefix[i]==prefix[j]+k