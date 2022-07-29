/*
 * @Author: xinyu Li
 * @Date: 2021-11-01 11:06:41
 * @LastEditTime: 2021-11-05 13:27:14
 * @Description: 
 * @FilePath: \helloworld\fuck\Graph\A1003.cpp
 * I am because you are
 */
//无向图
#include<bits/stdc++.h>
using namespace std;
const int maxn = 1010;
const int INF = 1000000000;
int C1, C2, N, M;
int graph[maxn][maxn] = {0}, vis[maxn] = {0}, d[maxn], abl[maxn], a[maxn], num[maxn] = {0};
void Dijkstra(int s)
{
    memcpy(a, abl, sizeof(int)*M);
    fill(d, d+M, INF);//切勿使用memset
    d[s] = 0;
    num[s] = 1;
    a[s] = abl[s];
    for(int i=0;i<N;i++){
        int min = INF, v = -1;
        for(int j=0;j<N;j++)
            if(!vis[j] && min > d[j]) {min = d[j];v = j;}
        if(v == -1) return;  //说明剩下的点与起点s不连通
        vis[v] = 1;
        int w = d[v];
        for(int u=0;u<N;u++){
            if(!vis[u] && graph[v][u]){
                if(w + graph[v][u] < d[u]){
                    d[u] = w + graph[v][u];                              //只有在最短要求下有其他对路径的要求时可以考虑这个情况
                    a[u] = a[v] + abl[u];
                    num[u] = num[v];
                }else if(w + graph[v][u] == d[u]){
                    if(a[v] + abl[u] > a[u]) a[u] = a[v] + abl[u];
                    num[u] += num[v];  // 题目要求的是最短路径条数，而不是要求给出最短路径且最大点权的路径上的点，所以这行代码写在更新点权代码块外面
                }
            }
        }
    }
}
int main()
{
    cin>>N>>M>>C1>>C2;
    for(int i=0;i<N;i++) cin>>abl[i];
    for(int i=0;i<M;i++) {
        int a, b, c;
        cin>>a>>b>>c;
        graph[a][b] = c;
        graph[b][a] = c;
    }
    Dijkstra(C1);
    cout<<num[C2]<<" "<<a[C2]<<endl;
    system("pause");
}

/*
5 6 0 2
1 2 1 5 3
0 1 1
0 2 1
0 3 1
1 2 1
2 4 1
3 4 1
*/