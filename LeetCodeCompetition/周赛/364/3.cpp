class Solution {
public:
    long long maximumSumOfHeights(vector<int>& maxHeights) {
        long long mres = -1;
        vector<long long> dp(maxHeights.size()+1, 0);
        vector<long long> dp2(maxHeights.size()+1, 0);
        dp[0] = 0;
        dp2[0] = 0;
        stack<long long> st;
        st.push(0);
        for(int i=0;i<maxHeights.size();i++){
            while(st.top()!=0 && maxHeights[st.top()-1]>maxHeights[i]){
                st.pop();
            }
            dp[i+1] = dp[st.top()]+(i+1-st.top())*maxHeights[i];
            // cout<<dp[i+1]<<endl;
            st.push(i+1);
        }
        while(!st.empty()) st.pop();
        st.push(0);
        for(int i=maxHeights.size()-1;i>=0;i--){
            while(st.top()!=0 && maxHeights[maxHeights.size()-st.top()]>maxHeights[i]){
                st.pop();
            }
            dp2[maxHeights.size()-i] = dp2[st.top()]+(maxHeights.size()-i-st.top())*maxHeights[i];
            st.push(maxHeights.size()-i);
            // cout<<dp2[maxHeights.size()-i]<<endl;
        }
        for(int i=1;i<=maxHeights.size();i++){
            long long res = dp[i]+dp2[maxHeights.size()-i]; // 计算以每个下标元素为山顶时的元素和
            // cout<<res<<endl;
            if(res>mres) mres = res;
        } 
        return mres;
    }
};

// dp+单调栈优化

/**
 * ! dp[i]代表以i下标为山顶，所构成的左侧单调不减序列（不满足就削去部分值）的最大和
 * ! dp[i] = dp[j]+(i-j)*maxHeights[i]
 * ! 假定一个下标，以他为山顶的序列和为左侧单调不减序列和加上右侧单调不增序列和。
 * * 只要从左到右算一遍dp[i]，从右到左算一遍dp[i]即可
 */