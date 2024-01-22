#include<bits/stdc++.h>
using namespace std;
int n, m, a[100010], prefix[100010];
int main(){
    scanf("%d %d", &n, &m);
    for(int i=1;i<=n;i++) {
        scanf("%d", &a[i]);
        prefix[i] = prefix[i-1]+a[i];
    }
    for(int i=0;i<m;i++) {
        int l, r;
        scanf("%d %d", &l, &r);
        printf("%d\n", prefix[r]-prefix[l-1]);
    }
    return 0;
}