// 
class Solution {
public:
    vector<double> dicesProbability(int n) {
        int dp[12][12*12] = {0};
        int cnt = 0;
        for(int i=1;i<=6;i++){dp[1][i]=1;if(1==n)cnt+=dp[1][i];}
        for(int i=2;i<=n;i++){
            for(int j=i;j<=i*6;j++){
                for(int k=1;k<=j;k++){
                    dp[i][j] += dp[i-1][j-k]*dp[1][k];
                }
                if(i==n)cnt+=dp[i][j];
            }
        }
        // cout<<cnt<<endl;
        // for(int i=n;i<=n*6;i++) cout<<dp[n][i]<<" ";
        vector<double> ans; 
        for(int i=n;i<=n*6;i++) ans.push_back(dp[n][i]*1.0/cnt);
        return ans;
    }
};