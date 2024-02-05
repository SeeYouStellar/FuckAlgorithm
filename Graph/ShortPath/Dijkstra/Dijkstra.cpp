// 朴素Dijkstra算法：不使用堆优化（优先队列）---------O(v^2)
#include<bits/stdc++.h>
using namespace std;
int graph[100][100], dist[100], vis[100], n, src=0, dst=n-1;
void dijkstra() // 
{
    // ! fill函数和memset函数的区别：
    // * 1) fill函数填充每一个数组单元
    // * 2) memset函数填充每一个字节单元 
    fill(dist, dist+100, INT_MAX);
    dist[src] = 0;
    for(int i = 0; i < n; i++)
    {
        int min = INT_MAX, u = -1;
        for(int j = 0; j < n; j++)
        {
            if(!vis[j] && dist[j] < min)
            {
                min = dist[j];  
                u = j;
            }
        }
        vis[u] = 1;
        for(int j = 0; j < n; j++)
        {
            if(!vis[j] && graph[u][j] && dist[u] + graph[u][j] < dist[j])  //邻接表写法与邻接矩阵写法唯一区别：邻接表不用判断graph[u][j]是否存在
                dist[j] = dist[u] + graph[u][j];
        }
    }
}
int main()
{

}