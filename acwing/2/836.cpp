#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
int n, m, root[N];

int Find(int x) {
    if(root[x] == x) return x;
    root[x] = Find(root[x]);
    return root[x];
}

void Union(int a, int b) {
    int fa = Find(a);
    int fb = Find(b);
    if(fa!=fb) 
        root[fa] = fb;
}

void Init(){
    for(int i=1;i<=n;i++) 
        root[i] = i;
}
int main() {
    cin>>n>>m;
    Init();
    for(int i=0;i<m;i++) {
        char op;
        int a, b;
        cin>>op>>a>>b;
        if(op == 'M') Union(a, b);
        else{
            if(Find(a)!=Find(b)) cout<<"No\n";
            else cout<<"Yes\n";
        }
    }
    return 0;
}