#include<bits/stdc++.h>
using namespace std;
int vis[10];
vector<vector<int> > res;
vector<int> v;
void get(vector<int>& nums, int d, int maxd) {
    cout<<d<<endl;
    if(d >= maxd) {
        res.push_back(v);
        return;
    }
    for(int i=0;i<nums.size();i++) {
        if(!vis[i]) {
            vis[i] = 1;
            v.push_back(nums[i]);
            get(nums, d+1, maxd);
            v.erase(v.end()-1);
            vis[i] = 0;
        }
    }
}
vector<vector<int> > permute(vector<int>& nums) {
    get(nums, 0, nums.size());
    return res;
}
int main() {
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    permute(nums);
}

