// 堆优化的bellman_ford算法就是SPFA算法（Shortest Path Faster Algorithm）
#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 510;
struct edge
{
    int val;
    int dst;
    edge(int v, int d) : val(v), dst(d) {}
};
int n, m, c1, c2, d[maxn], v[maxn], vv[maxn], num[maxn], inqnum[maxn];// inqnum记录点入队的次数
bool inq[maxn];//inq记录是否在队列中，保持队列不重复
vector<edge> graph[maxn];

set<int> pre[maxn]; 

queue<int> q; // 用于堆优化
bool bellman_ford_queue()
{
    fill(d, d + maxn, INF);

    d[c1] = 0;
    vv[c1] = v[c1];
    num[c1] = 1;
    inq[c1] = 1;
    inqnum[c1] = 1;
    q.push(c1);

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        inq[u] = 0;
        for (int i = 0; i < graph[u].size(); i++)
        {
            int j = graph[u][i].dst;
            int w = graph[u][i].val;
            int flag = 0;
            if (d[j] > d[u] + w)
            {
                d[j] = d[u] + w;
                vv[j] = vv[u] + v[j];
                pre[j].clear();
                pre[j].insert(u);
                num[j] = num[u];
                flag = 1;
            }
            else if (d[j] == d[u] + w)
            {
                if (vv[j] < vv[u] + v[j])
                {
                    vv[j] = vv[u] + v[j];
                }
                flag = 1;
                pre[j].insert(u);
                num[j] = 0;
                for (set<int>::iterator it = pre[j].begin(); it != pre[j].end(); it++)
                {
                    num[j] += num[*it];
                }
            }
            // 只要进入过上面两个分支，即更改过点权、边权、最短路径条数都需要入队，因为与该点连通的点都需要再次更新
            if(flag){
                if(!inq[j]){
                    q.push(j);
                    inqnum[j]++;
                    inq[j] = 1;
                    if(inqnum[j]>n-1) return false;  //判断负环
                }
            }
        }
    }
    return true;
}
int main()
{
    cin >> n >> m >> c1 >> c2;
    for (int i = 0; i < n; i++)
        cin >> v[i];
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back(edge(c, b));
        graph[b].push_back(edge(c, a));
    }
    bellman_ford_queue();
    
    system("pause");
}