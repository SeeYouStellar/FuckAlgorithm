// 堆优化Dijkstra算法
#include<bits/stdc++.h>
using namespace std;
int graph[100][100], dist[100], vis[100], n, src=0, dst=n-1;
void dijkstra()
{
    fill(d, d+100, INT_MAX);
    dist[src] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, src));
    while(!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        if(vis[u]) continue; // 因为vis数组只是为了记录节点是否已找到最短路径而不是为了记录是否入队，所以注意这种写法会导致多个节点的不同长度路径被记录，当某条记录被弹出后，其余的该节点的记录就都废掉了。
        vis[u] = 1;
        for(int j = 0; j < n; j++)
        {
            if(!vis[j] && graph[u][j] && dist[u] + graph[u][j] < dist[j])
            {
                dist[j] = dist[u] + graph[u][j];
                pq.push(make_pair(dist[j], j));
            }
        }
    }
}
int main()
{

}