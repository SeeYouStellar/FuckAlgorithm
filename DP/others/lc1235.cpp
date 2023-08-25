/*
1235. 规划兼职工作

题目：
你打算利用空闲时间来做兼职工作赚些零花钱。

这里有 n 份兼职工作，每份工作预计从 startTime[i] 开始到 endTime[i] 结束，报酬为 profit[i]。

给你一份兼职工作表，包含开始时间 startTime，结束时间 endTime 和预计报酬 profit 三个数组，请你计算并返回可以获得的最大报酬。

注意，时间上出现重叠的 2 份工作不能同时进行。

如果你选择的工作在时间 X 结束，那么你可以立刻进行在时间 X 开始的下一份工作。

思路：
与lc2830一个思路
*/

class Solution {
public:
    static bool cmp(vector<int>& x, vector<int>& y){
        if(x[1]==y[1]) return x[0]<y[0];
        return x[1]<y[1];
    }
    int binarySearch(vector<vector<int>>& x, int l, int r, int target){
        while(l<=r){
            int mid = (l+r)>>1;
            if(x[mid][1]>target) r=mid-1;
            else l=mid+1;
        }
        return l;
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>> offers(n);
        for(int i=0;i<n;i++) {
            offers[i].push_back(startTime[i]);
            offers[i].push_back(endTime[i]);
            offers[i].push_back(profit[i]);
        }
        sort(offers.begin(), offers.end(), cmp);
        int dp[50010];
        dp[0]=offers[0][2];
        for(int i=1;i<n;i++){
            int index = binarySearch(offers, 0, i-1, offers[i][0]);
            index--;
            int tmp = index!=-1?dp[index]:0;
            dp[i] = max(dp[i-1], tmp+offers[i][2]);
        }
        return dp[n-1];
    }
};