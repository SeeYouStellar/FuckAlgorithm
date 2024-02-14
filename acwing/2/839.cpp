#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+100;
int n, a[N], k, m, idx_k[N], k_idx[N];

void down(int p) {
    int q = p*2;
    while(q<=n) {
        if(q+1<=n && a[q]>a[q+1]) q = q+1;
        if(a[p]>a[q]){
            int kp = idx_k[p], kq = idx_k[q];
            swap(idx_k[p], idx_k[q]);
            swap(k_idx[kp], k_idx[kq]);
            swap(a[p], a[q]);
            p = q;
            q = p*2;
        }else break;
    }
}
void up(int p) {
    int q = p/2;
    while(q>0){
        if(a[p]<a[q]){
            int kp = idx_k[p], kq = idx_k[q];
            swap(idx_k[p], idx_k[q]);
            swap(k_idx[kp], k_idx[kq]);
            swap(a[p], a[q]);
            p = q;
            q = q/2;
        } else break;
    }
}
void delete_k(int p) {
    int kp = idx_k[p], kn = idx_k[n];
    swap(idx_k[p], idx_k[n]);
    swap(k_idx[kp], k_idx[kn]);
    swap(a[p], a[n]);
    
    n--;
    // ! 注意这里两种情况只会发生一种，即向上调整或向下调整
    down(p);
    up(p);
    
}

void top() {
    cout<<a[1]<<endl;
}

void update_k(int p, int x) {
    a[p] = x; 
    // ! 注意这里两种情况只会发生一种，即向上调整或向下调整
    down(p);
    up(p);
}
void insert(int x) {
    a[++n] = x;
    idx_k[n] = ++k;
    k_idx[k] = n;
    up(n);
}

void prt() {
    for(int i=1;i<=n;i++) {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
int main() {
    cin>>m;
    for(int i=0;i<m;i++) {
        char op[2];
        cin>>op;
        int x, k;
        if(op[0]=='I') {
            cin>>x;
            insert(x);
        } else if(op[0]=='P') {
            top();
        } else if(op[0]=='D' && op[1]=='M') {
            delete_k(1);
        } else if(op[0]=='D') {
            cin>>k;
            delete_k(k_idx[k]);
        } else {
            cin>>k>>x;
            update_k(k_idx[k], x);
        } 
        // prt();
    }
    return 0;
}
