#include<bits/stdc++.h>
using namespace std;

const int N = 32*1e5;
int n, trie[N][2], res, idx;

void insert(int x) {
    int a[32];
    for(int i=0;i<32;i++) {
        if(x){
            a[31-i] = x&1;
            x>>=1;
        }else
            a[31-i] = 0;
    }
    int p = 0, q = 0, x_o_r = 0, flag = 1;
    for(int i=0;i<32;i++) {
        
        int u = a[i];
        if(!trie[p][u]) trie[p][u] = ++idx;
        p = trie[p][u];
        
        if(flag && trie[q][!u]) {
            x_o_r+=pow(2,31-i);
            q = trie[q][!u];
        }else if(flag && trie[q][u]){
            q = trie[q][u];
        }else {
            flag = 0;
        }
        // cout<<p<<" "<<q<<endl;
    }
    if(res<x_o_r) res = x_o_r;
}

int main() {
    cin>>n;
    for(int i=0;i<n;i++) {
        int x;
        cin>>x;
        insert(x);
    }
    cout<<res<<endl;
}