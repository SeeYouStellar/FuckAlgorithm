/*
 * @Author: xinyu Li
 * @Date: 2021-11-08 09:46:13
 * @LastEditTime: 2021-11-09 23:40:02
 * @Description: 
 * @FilePath: \helloworld\fuck\Graph\ShortPath\Dijkstra\A1018.cpp
 * I am because you are
 */
#include<bits/stdc++.h>
using namespace std;
const int maxn = 510;
const int INF = 100000;
int Cmax, N, sp, M, bests = INF, bestb = INF, send = 0, back = 0;  //最大容量 站数量 问题站 边数 最少带去 带回
int Cap[maxn], G[maxn][maxn], d[maxn], vis[maxn];
vector<int> Prev[maxn], path, tmp;
void Dijkstra(int s)
{
    fill(d, d+maxn, INF);
    d[s] = 0;
    for(int i=0;i<=N;i++){
        int u = -1, tmp = INF;
        for(int j=0;j<=N;j++)
            if(!vis[j] && tmp > d[j]){tmp = d[j];u = j;}
        if(u == -1) return;
        vis[u] = 1;
        for(int j=0;j<=N;j++){
            if(!vis[j] && G[u][j] != INF){
                if(d[j] > d[u] + G[u][j]){
                    d[j] = d[u] + G[u][j];
                    Prev[j].clear();
                    Prev[j].push_back(u);
                }else if(d[j] == d[u] + G[u][j])
                    Prev[j].push_back(u);
            }
        }
    }
}

void bike()
{
    int a;
    for(int i=1;i<tmp.size();i++){
        a = abs(Cap[tmp[i]] - Cmax);
        if(Cap[tmp[i]] > Cmax)
            back += a;
        else if(Cap[tmp[i]] < Cmax){
            if(a > back) {send += a - back;back = 0;}
            else back -= a;
        }
    }
}
void DFS(int root)
{
    if(root == 0){
        reverse(tmp.begin(), tmp.end());
        bike();
        if(send < bests){
            bests = send;
            bestb = back;
            path = tmp;
            send = 0;
            back = 0;
        }else if(send == bests && back < bestb){
            bestb = back;
            bests = send;
            path = tmp;
            send = 0;
            back = 0;
        }
        reverse(tmp.begin(), tmp.end());
    }
    for(int i=0;i<Prev[root].size();i++){
        tmp.push_back(Prev[root][i]);
        DFS(Prev[root][i]);
        tmp.pop_back();
    }
}
int main()
{
    cin>>Cmax>>N>>sp>>M;
    Cmax /= 2;
    for(int i=1;i<=N;i++) cin>>Cap[i];
    fill(G[0], G[0]+maxn*maxn, INF);
    for(int i=0;i<M;i++){
        int a, b;
        cin>>a>>b;
        cin>>G[a][b];
        G[b][a] = G[a][b];
    }
    Dijkstra(0);

    tmp.push_back(sp);
    DFS(sp);

    cout<<bests<<" ";
    for(int i=0;i<path.size();i++){
        cout<<path[i];
        if(i < path.size() - 1) cout<<"->";
    }
    cout<<" "<<bestb;
    system("pause");
}
