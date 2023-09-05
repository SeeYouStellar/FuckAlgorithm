class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int prefix[200010] = {0};
        unordered_map<int, vector<int>> m;  // 哈希表：存储前缀和取模后相同的每个下标（用vector存储），
        m[0].push_back(0);
        int ret = 0;
        for(int i=1;i<=nums.size();i++){
            prefix[i] = prefix[i-1]+nums[i-1];
            int modulo = prefix[i]%k;
            if(m.count(modulo)!=0){  
                int j=m[modulo].size()-1;
                while(j>=0 && i-m[modulo][j]<2)
                    j--;
                ret+=j+1;
            } 
            m[modulo].push_back(i);
        }
        return ret>=1;
    }
};

// (prefix[i]-prefix[j]) % k == 0, i-j>=2