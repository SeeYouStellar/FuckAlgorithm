#include<bits/stdc++.h>
using namespace std;
int a[1010][1010];
int prefix[1010][1010];
int n, m, q;
int main() {
    scanf("%d %d %d", &n, &m, &q);
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            scanf("%d", &a[i][j]);
            prefix[i][j] = a[i][j]+prefix[i-1][j]+prefix[i][j-1]-prefix[i-1][j-1];
        }
    }
    for(int i=0;i<q;i++) {
        int x1, x2, y1, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        printf("%d\n", prefix[x2][y2]-prefix[x1-1][y2]-prefix[x2][y1-1]+prefix[x1-1][y1-1]);
    }
    return 0;
}