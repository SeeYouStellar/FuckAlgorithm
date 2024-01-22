#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int n, a[N], b[N];

void sort(int l1, int r1, int l2, int r2) {
    int i = l1, j = l2, idx = 0;
    while(i<=r1 && j<=r2) {
        if(a[i]<a[j]) b[idx++] = a[i++];
        else b[idx++] = a[j++];
    }
    while(i<=r1) b[idx++] = a[i++];
    while(j<=r2) b[idx++] = a[j++];
    // for(int i=0;i<idx;i++) a[l1+i] = b[i];
    memcpy(a+l1, b, idx*sizeof(int));
    memset(b, 0, idx*sizeof(int));
}
void merge(int l, int r) {
    if(l == r) return;
    int mid = (l+r)>>1;
    merge(l, mid);
    merge(mid+1, r);
    sort(l, mid, mid+1, r);
}
int main() {
    scanf("%d", &n);
    for(int i=0;i<n;i++) scanf("%d", &a[i]);
    merge(0, n-1);
    for(int i=0;i<n;i++) printf("%d ", a[i]);
}