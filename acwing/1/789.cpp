#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;

int n, q, k, a[N];

// 大于等于k的第一个数
int lower_bound(int l, int r, int k) {
    int i = l, j = r;
    while(l<=r) {
        int mid = l+r>>1;
        if(a[mid]>=k) r = mid-1;
        else l = mid+1;
    }
    return l;
}
int main() {
    scanf("%d%d", &n, &q);
    for(int i=0;i<n;i++) scanf("%d", &a[i]);
    for(int i=0;i<q;i++) {
        scanf("%d", &k);
        int l = lower_bound(0, n-1, k), r;
        if(l>=n && a[l]!=k) cout<<"-1 -1"<<endl;
        else{
            r = lower_bound(0, n-1, k+1)-1;
            cout<<l<<" "<<r<<endl;
        }
    }
    return 0;
}