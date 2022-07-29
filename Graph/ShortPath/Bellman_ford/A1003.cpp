#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
struct edge{
    int val;
    int dst;
    edge(int v, int d):val(v),dst(d){}
};
int n, m, c1, c2, d[500+10], v[500+10], vv[500+10], num[500+10];
vector<edge> graph[500+10];

set<int> pre[500+10];  //与dijkstra的区别：每次找到相同长度路径时要重新统计到该点的路径条数，自然需要记录所有前驱节点，因为可能会有相同的前驱节点来更新当前节点，故用set去重
void bellman_ford()
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
                    for(set<int>::iterator it = pre[u].begin();it!=pre[u].end();it++){//重新计算
                        num[u]+=num[*it];
                    }
                }
            }
        }
    }
}
queue<int> q;  // 用于堆优化
void bell_ford_queue()
{
    
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
        graph[b].push_back(edge(c, c));
    }
    bellman_ford();
    cout<<num[c2]<<" "<<vv[c2]<<endl;
    system("pause");
}