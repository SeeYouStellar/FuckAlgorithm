/*

将offers按end从小到大排序（背包问题的思路）

dp[i]代表总共有i个offer时，收入的最大值

dp[i] = max{dp[i-1], dp[j]+offers[i][2]}  j满足0<=j<i，且offers[j][1]<offers[i][0]

dp[i-1]是指不卖第i个offer中所包含范围内的房子，dp[j]+offers[i][2]是指卖第i个offer中所包含范围内的房子，但要找到不冲突的offer

寻找不冲突的offer下标可以用二分优化
*/

class Solution {
public: 
    
    static bool cmp(vector<int>& x,vector<int>& y) {
        if(x[1] == y[1])return x[0] < y[0];
        return x[1] < y[1];
    }
    int binarySearch(vector<vector<int>>& x, int target, int l, int r) {
        // 找大于等于target的第一个数
        while(l<=r){
            int mid = (l+r)/2;
            if(x[mid][1]<target){
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        return l;
    }
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        sort(offers.begin(), offers.end(), cmp);
        int dp[100010]={0};
        dp[0] = offers[0][2]; 
        for(int i=1;i<offers.size();i++){
            int index = binarySearch(offers, offers[i][0], 0, i-1);
            index--; // index offers[j][1]小于offers[i][0]的最大下标
            int tmp = index!=-1?dp[index]:0;
            dp[i] = max(dp[i-1], offers[i][2]+tmp);
            printf("index:%d dp[i]:%d\n", index, dp[i]);
        }
        return dp[offers.size()-1];
    }
};