class Solution {
public:
    int dp[1010][1010];
    string longestPalindrome(string s) {
        if(s.size()==1)return s;
        string res=s.substr(0, 1);
        for(int i=0;i<s.size()-1;i++){
            dp[i][i] = 1;
            if(s[i] == s[i+1]){
                dp[i][i+1] = 1;
                res = s.substr(i, 2);
            }
        }
        dp[s.size()-1][s.size()-1] = 1;
        for(int step=3;step<=s.size();step++){
            for(int i=0;i<=s.size()-step;i++){
                int j = i+step-1;
                if(s[i] == s[j] && dp[i+1][j-1] == 1) {
                    dp[i][j] = 1;
                    res = s.substr(i, step);
                }
            }
        }
        return res;
    }
};