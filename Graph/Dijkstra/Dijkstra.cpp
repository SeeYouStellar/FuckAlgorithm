/*
 * @Author: xinyu Li
 * @Date: 2021-11-06 16:31:20
 * @LastEditTime: 2021-11-07 18:52:44
 * @Description: 简述Dijkstra
 * @FilePath: \helloworld\fuck\Graph\Dijkstra\Dijkstra.cpp
 * I am because you are
 * 
 * 
 * 给的图中会有到某个点的相同长度的路径，这时候长度属于第一标尺，会有第二个标尺来判断哪个是最优
 */
#include<bits/stdc++.h>
using namespace std;
const int maxn = 10000;
const int INF = 1000000;
int vis[maxn] = {0}, G[maxn][maxn] = {INF}, d[maxn], abl[maxn];
int N, M, S, D;
vector<int> pre[maxn]; //记录到每个节点的最佳路径的上该节点的父节点
void Dijkstra(int s)
{
    fill(d, d+maxn, INF);
    d[s] = 0; //源点的最短距离为0
    for(int i=0;i<N;i++){
        int v = -1, tmp = INF;
        for(int j=0;j<N;j++)
            if(!vis[j] && d[j] < tmp){tmp = d[j];v = j;}
        if(v == -1) return;
        vis[v] = 1;
        for(int j=0;j<N;j++){
            if(!vis[j] && G[v][j] != INF){
                if(d[j] > d[v] + G[v][j]){  
                    d[j] = d[v] + G[v][j];
                    pre[j].clear();
                    pre[j].push_back(v);
                }else if(d[j] == d[v] + G[v][j])  
                    pre[j].push_back(v);
            }
        }
    }
}
int a = 0; //最大救护车数
vector<int> v, tmp; //当前最优路径  递归临时路径
void DFS(int root, int count)
{   
    int size = pre[root].size();
    if(root == S) //
        if(count > a){
            a = count;
            v.assign(tmp.begin(), tmp.end());
        }
    for(int i=0;i<size;i++){
        int next = pre[root][i];
        tmp.push_back(next);
        DFS(next, count+abl[next]);
        tmp.pop_back();
    }
}
int main()
{
    cin>>N>>M>>S>>D;
    for(int i=0;i<N;i++) cin>>abl[i];
    fill(G[0], G[0]+maxn*maxn, INF);
    for(int i=0;i<M;i++){
        int a, b;
        cin>>a>>b;
        cin>>G[a][b];
        G[b][a] = G[a][b];
    }
    Dijkstra(S);
    DFS(D, abl[S]);
    cout<<a<<endl;
    cout<<"\n";
    for(int i=v.size()-1;i>=0;i--)
        cout<<v[i]<<" ";
    cout<<D;
    system("pause");
}