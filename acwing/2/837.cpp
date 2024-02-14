#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
int n, m, father[N], cnt[N];

int Find(int x) {
    if(father[x] == x) return x;
    father[x] = Find(father[x]);
    return father[x];
}

void Union(int a, int b) {
    int fa = Find(a);
    int fb = Find(b);
    if(fa != fb) {
        father[fa] = fb;
        cnt[fb] += cnt[fa];  // 每个连通块内节点个数只需要统一到根节点上就行
    }
}

void Init() {
    for(int i=1;i<=n;i++) {
        father[i] = i;
        cnt[i] = 1;
    }        
}

int main() {
    cin>>n>>m;
    Init();
    for(int i=0;i<m;i++) {
        char op[2];
        cin>>op;
        if(op[0] == 'C') {
            int a, b;
            cin>>a>>b;
            Union(a, b);
        }else if(op[1] == '1') {
            int a, b;
            cin>>a>>b;
            cout<<(Find(a)==Find(b)?"Yes":"No")<<endl;
        }else {
            int a;
            cin>>a;
            cout<<cnt[Find(a)]<<endl;
        }
    }
    return 0;
}