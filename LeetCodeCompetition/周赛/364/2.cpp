class Solution {
public:
    long long maximumSumOfHeights(vector<int>& maxHeights) {
        long long mres = -1;
        for(int i=0;i<maxHeights.size();i++){
            long long res = maxHeights[i];
            int target = maxHeights[i];
            for(int j=i-1;j>=0;j--){
                if(maxHeights[j]<=target){
                    res+=maxHeights[j];
                    target = maxHeights[j];
                }else{
                    res+=target;
                }
                // cout<<target<<" "<<res<<endl;
            }
            target = maxHeights[i];
            for(int j=i+1;j<maxHeights.size();j++){
                if(maxHeights[j]<=target){
                    res+=maxHeights[j];
                    target = maxHeights[j];
                }else{
                    res+=target;
                }
            }
            // cout<<i<<" "<<res<<endl;
            if(res>mres)mres = res;
        }
        return mres;
    }
};