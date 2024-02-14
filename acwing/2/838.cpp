#include<bits/stdc++.h>
using namespace std;

// 小顶堆
const int N = 1e5+100;
int a[N], n, m;

void down(int p) {
    int q = p*2;
    while(q<=n) {
        if(q+1<=n && a[q]>a[q+1]) q = q+1;
        if(a[p]>a[q]){
            swap(a[p], a[q]);
            p = q;
            q = p*2;
        }else break;
    }
}

void delete_() {
    a[1] = a[n];
    n --;
    down(1);
}

void heapsort(int m) {
    for(int i=0;i<m;i++) {
        cout<<a[1]<<" ";
        delete_();
    }
}

void init() {
    for(int i=n/2;i>=1;i--) {
        down(i);
    }
}
int main() {
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    init();
    heapsort(m);
    return 0;
}