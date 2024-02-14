#include<bits/stdc++.h>
using namespace std;
// 维护一个并查集，这个并查集里用节点与到根节点之间的距离来代表该节点所属的动物类和吃的关系
// 题目中所有节点只有在一个并查集里或还没合并至这个并查集两种可能，最后形成的并查集一定是一个三个动物类的环（题意）
// 两个节点(d[x]-d[y])%3==0说明他们是同类（并不是说同一个并查集，如果此时pa!=pb则需要合并，如果pa==pb那就不需要做任何事）
// 两个节点(d[x]-d[y]-1)%3==0说明x吃y
const int N = 5e4+100;
int n, k, p[N], res, d[N];

int find(int x) {
    if(p[x] != x) {
        int u = find(p[x]);
        d[x] += d[p[x]];
        p[x] = u;
    }
    return p[x];
}

int main() {
    cin>>n>>k;
    for(int i=1;i<=n;i++) {p[i] = i;}
    for(int i=0;i<k;i++) {
        int t, a, b;
        cin>>t>>a>>b;
        if(a>n || b>n) res++;
        else if(t == 2 && a == b) res++;
        else {
            int pa = find(a), pb = find(b);
            if(t == 1) {
                if(pa == pb && (d[a]-d[b])%3) res++;
                else if(pa != pb) {
                    // 前面的输入如果是真话，就会进行合并操作
                    // pa!=pb说明在之前这两个节点并没有进行合并操作，所以这种情况下默认是真话
                    p[pa] = pb;
                    d[pa] = d[b] - d[a];
                }
            }else{
                if(pa == pb && (d[a]-d[b]-1)%3) res++;
                else if(pa != pb) {
                    // 前面的输入如果是真话，就会进行合并操作
                    // pa!=pb说明在之前这两个节点并没有进行合并操作，所以这种情况下默认是真话
                    p[pa] = pb;
                    d[pa] = d[b] - d[a] + 1;
                }
            }
        }
    }
    cout<<res;
}
