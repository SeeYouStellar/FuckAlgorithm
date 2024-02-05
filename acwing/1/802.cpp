#include<bits/stdc++.h>
using namespace std;

const int N = 3e5+10;
vector<pair<int, int>> a, q; // a代表adds，q代表querys
unordered_map<int, int> map_; // 下标映射
vector<int> alls;  //需要离散化的下标
int tmp[N], sum[N];  // tmp代表离散化后的数组，其下标即为离散化后的数据下标范围，sum为前缀和数组

int n, m;

int main() {
    cin>>n>>m;
    for(int i=0;i<n;i++) {
        int x, c;
        cin>>x>>c;
        a.push_back(make_pair(x, c));
        alls.push_back(x);
    }
    for(int i=0;i<m;i++) {
        int l, r;
        cin>>l>>r;
        q.push_back(make_pair(l, r));
        alls.push_back(l);
        alls.push_back(r);
    }
    
    // ! 离散化的标准方法，即排序+去重+映射
    sort(alls.begin(), alls.end());
    alls.erase(unique(alls.begin(), alls.end()), alls.end());
    for(int i=1;i<=alls.size();i++) {  // ! 为了计算前缀和方便从1开始映射
        map_[alls[i-1]] = i;
    }

    // ! 给离散化后的数组添加值
    for(auto& add:a) {
        int x = map_[add.first];
        tmp[x] += add.second;
    }
    for(int i=1;i<=alls.size();i++) {
        sum[i] = sum[i-1]+tmp[i];
    }
    
    for(auto& query:q) {
        int l = map_[query.first];
        int r = map_[query.second];
        cout<<sum[r]-sum[l-1]<<endl;
    }
    return 0;
}

// ? 离散化：把一个大区间的下标范围缩小到一个小区间的下标范围，可以理解成一个下标映射的过程
// ! 本题将2e9的数据范围映射到了3e5
