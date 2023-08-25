// 与lc1235 2830 一样
class Solution {
public:
    static bool cmp(vector<int>& x, vector<int>& y) {
        return x[1]<y[1];
    }
    int BinarySearch(vector<vector<int>>& x, int l, int r, int target) {
        while(l<=r){
            int mid = (l+r)>>1;
            if(x[mid][1]>target) r=mid-1;
            else l=mid+1;
        }
        return l;
    }
    long long max_(long long x, long long y){
        return x>y?x:y;
    }
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        sort(rides.begin(), rides.end(), cmp);
        for(int i=0;i<rides.size();i++){
            rides[i][2] = rides[i][1]-rides[i][0]+rides[i][2];
        }
        long long dp[30010];
        dp[0] = rides[0][2];
        for(int i=1;i<rides.size();i++){
            int index=BinarySearch(rides, 0, i-1, rides[i][0]);
            index--;
            long long tmp = index!=-1?dp[index]:0;
            dp[i] = max_(dp[i-1], tmp+rides[i][2]);
        }
        return dp[rides.size()-1];
    }
};