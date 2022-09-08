
#include<bits/stdc++.h>
using namespace std;
const int maxn = 510;
const int INF = 0x3f3f3f3f;
int g[maxn][maxn], vis[maxn], dis[maxn], cost[maxn][maxn];
vector<int> path[maxn];
int n, m, s, d;
void dijkstra()
{
    fill(dis, dis+maxn, INF);
    dis[s] = 0;
    for(int i=0;i<n;i++){
        int min_ = INF, u = -1;
        for(int j=0;j<n;j++){
            if(!vis[j]&&dis[j]<min_){
                min_ = dis[j];
                u = j;
            }
        }
        if(u==-1)return;
        vis[u] = 1;
        for(int j=0;j<n;j++){
            if(!vis[j]&&g[u][j]){
                if(dis[j]>dis[u]+g[u][j]){
                    dis[j]=dis[u]+g[u][j];
                    path[j].clear();
                    path[j].push_back(u);
                }else if(dis[j]==dis[u]+g[u][j]){
                    path[j].push_back(u);
                }
            }
        }
    }
}
int minc=INF;
vector<int> bestpath;
vector<int> ans;
void dfs(int root, int c)
{
//     cout<<root<<" "<<c<<endl;
    if(root==s){
        bestpath.push_back(root);
        if(c<minc){
            minc=c;
            ans = bestpath;
        }
        bestpath.pop_back();
        return;
    }
    bestpath.push_back(root);
    for(int i=0;i<path[root].size();i++){
        dfs(path[root][i], c+cost[root][path[root][i]]);
    }
    bestpath.pop_back();
}
int main()
{
    cin>>n>>m>>s>>d;
    for(int i=0;i<m;i++){
        int a, b, w, c;
        cin>>a>>b>>w>>c;
        g[a][b] = g[b][a] = w;
        cost[a][b] = cost[b][a] = c;
    }
    dijkstra();
    dfs(d, 0);
    for(int i=ans.size()-1;i>=0;i--){
        cout<<ans[i]<<" ";
    }
    cout<<dis[d]<<" "<<minc<<endl;
    return 0;
}


