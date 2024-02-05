#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
int n, a[N], res;
unordered_map<int, int> umap;

int main() {
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];

    for(int i=0, j=0;i<n;i++) {
        umap[a[i]]++;
        while(umap[a[i]]>1) 
            umap[a[j++]]--;
        res = max(res, i-j+1);
    }
    cout<<res;
    return 0;
}

/*
? 枚举i
? j表示以i为右端点，最左可到达的使连续序列元素不重复的下标位置
! i和j满足一定的单调性，当i向右移动时，j只能向右移动，而不能向左
*/