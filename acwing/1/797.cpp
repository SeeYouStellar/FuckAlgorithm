// 一维差分
#include<bits/stdc++.h>
using namespace std;

int n, m, a[100010], b[100010];

void insert(int l, int r, int c) {
    b[l] += c;
    b[r+1] -= c;
}
int main() {
    scanf("%d%d", &n, &m);
    for(int i=1;i<=n;i++) {
        scanf("%d", &a[i]);
        insert(i, i, a[i]);
    }
    for(int i=0;i<m;i++) {
        int l, r, c;
        scanf("%d%d%d", &l, &r, &c);
        insert(l, r, c);
    }
    for(int i=1;i<=n;i++) {
        b[i] = b[i-1]+b[i];
        printf("%d ", b[i]);
    }
    system("pause");
}