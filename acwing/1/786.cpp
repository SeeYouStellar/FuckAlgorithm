#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;

int n, k, a[N];

int quick_sort(int l, int r, int k) {
    if(l == r) return a[l];
    int i = l-1, j = r+1, v = a[l+r>>1];
    while(i<j) {
        do i++;while(a[i]<v);
        do j--;while(a[j]>v);
        if(i<j) swap(a[i], a[j]);
    }
    int sl = j-l+1;
    if(k<=sl)
        return quick_sort(l, j, k);
    else 
        return quick_sort(j+1, r, k-sl);
}

int main() {
    scanf("%d%d", &n, &k);
    for(int i=0;i<n;i++) scanf("%d", &a[i]);
    cout<<quick_sort(0, n-1, k);
    return 0;
}