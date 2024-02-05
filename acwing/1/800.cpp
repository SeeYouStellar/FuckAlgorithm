#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
int n, m, x, a[N], b[N];

int main() {
    scanf("%d%d%d", &n, &m, &x);
    for(int i=0;i<n;i++) scanf("%d", &a[i]);
    for(int i=0;i<m;i++) scanf("%d", &b[i]);
    int l = 0, r = m-1;
    while(l<n && r>=0) {
        int sum = a[l] + b[r];
        
        while(r>=0 && sum>x) {
            r--;
            sum = a[l] + b[r];
        }
        if(sum == x) break;
        l++;
    }
    cout<<l<<" "<<r;
    return 0;
}