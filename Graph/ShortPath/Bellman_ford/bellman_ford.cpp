#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
struct edge{
    int val;
    int dst;
    edge(int v, int d):val(v),dst(d){}
};
int n, m, c1, c2, d[500+10], v[500+10], vv[500+10], num[500+10]; // 涉及边权、点权、最短路径条数的更新
vector<edge> graph[500+10];  //邻接表写法
set<int> pre[500+10];    // 记录前驱节点
bool bellman_ford()
{
    fill(d, d+510, INF);
    d[c1] = 0;
    num[c1] = 1;
    vv[c1] = v[c1]; 
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<graph[j].size();k++){
                int u = graph[j][k].dst;
                int w = graph[j][k].val;
                if(d[u] > d[j] + w){
                    d[u] = d[j] + w;
                    vv[u] = vv[j]+v[u];
                    pre[u].clear();
                    pre[u].insert(j);
                    num[u]=num[j];
                }else if(d[u] == d[j]+w){
                    if(vv[u]<vv[j]+v[u]){
                        vv[u] = vv[j]+v[u];
                    }
                    pre[u].insert(j);
                    num[u] = 0;
                    // 与dijkstra更新最短路径条数的区别
                    for(set<int>::iterator it = pre[u].begin();it!=pre[u].end();it++){//重新计算
                        num[u]+=num[*it];
                    }
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<graph[i].size();j++){
            if(d[graph[i][j].dst] > d[i]+graph[i][j].val) //经过n-1次更新后仍有点可更新，一定存在负环
                return false;
        }
    }
    return true;
}
int main()
{
    cin >> n >> m>> c1 >> c2;
    for(int i = 0; i < n; i++)
        cin >> v[i];
    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back(edge(c, b));
        graph[b].push_back(edge(c, a));
    }
    bellman_ford();
    system("pause");
}