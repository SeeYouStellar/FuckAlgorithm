class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, int> map;
        for(auto& word:wordDict) map[word] = 1;
        vector<int> dp(s.size()+1, 0);
        dp[0] = 1;
        for(int i=1;i<=s.size();i++){
            for(int j=i-1;j>=0;j--){
                if(dp[j]==1){
                    string tmp = s.substr(j, i-j);
                    if(map.count(tmp)!=0)dp[i]=1;
                }
            }
        }
        return dp[s.size()];
    }
};

// 字符串DP