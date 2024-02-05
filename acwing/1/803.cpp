#include<bits/stdc++.h>
using namespace std;

int n;
vector<pair<int, int>> v;
// sort函数自定义排序函数
bool cmp(pair<int, int>& a, pair<int, int>& b) {
    if(a.first == b.first){
        return a.second<b.second;
    }
    return a.first<b.first;
}

int main() {
    cin>>n;
    int a, b;
    for(int i=0;i<n;i++) {
        cin>>a>>b;
        v.push_back(make_pair(a, b));
    }
    
    sort(v.begin(), v.end(), cmp);
    
    int cnt = 1;
    int last = v[0].second;
    
    for(int i=1;i<v.size();i++) {
        pair<int, int> x = v[i];
        if(x.first > last) {
            cnt ++;
        }
        if(last<x.second)
            last = x.second;
    }
    cout<<cnt;
    return 0;
}