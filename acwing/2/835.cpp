#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+100;
int node[N][26], cnt[N], n, m; // n代表目前trie中有几个节点
char s[N];

void insert(char s[]) {
    int  p = 0;
    for(int i=0;s[i];i++) {
        int u = s[i]-'a';
        if(!node[p][u]) node[p][u] = ++n;
        p = node[p][u];
    }
    cnt[p]++;
}

int query(char s[]) {
    int p = 0;
    for(int i=0;s[i];i++) {
        int u = s[i]-'a';
        if(!node[p][u]) return 0;
        p = node[p][u];
    }
    return cnt[p];
}
int main() {
    cin>>m;
    for(int i=0;i<m;i++) {
        char op;
        cin>>op>>s;
        if(op == 'I') {
            insert(s);
        }else {
            cout<<query(s)<<endl;
        }
    }
    return 0;
}