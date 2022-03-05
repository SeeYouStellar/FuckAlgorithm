/*
 * @Author: xinyu Li
 * @Date: 2021-10-30 16:15:16
 * @LastEditTime: 2022-03-04 09:44:10
 * @Description: 
 * @FilePath: \helloworld\fuck\Graph\A1076\A1076.cpp
 * I am because you are
 */
#include<bits/stdc++.h>
using namespace std;
const int maxn = 1010;
const int INF = 1000000;
int graph[maxn][maxn], vis[maxn];
int n, l;
int bfs(int root)
{
    queue<int> q;
    q.push(root);
    vis[root] = 1;
    int size, lev = 0, cnt = 0;
    while(!q.empty()){
        size = q.size();
        if(lev==l) return cnt; 
        lev++;
        for(int i=0;i<size;i++){
            int top = q.front();
            q.pop();
            for(int j=1;j<=n;j++){
                if(!vis[j] && graph[top][j]!=INF){
                    q.push(j);
                    vis[j] = 1;
                    cnt++;
                }
            }
        }
    }
    return cnt;
}
int main()
{
    cin>>n>>l;
    int k, a;
    fill(graph[0], graph[0]+maxn*maxn, INF);
    for(int i=0;i<n;i++){
        cin>>k;
        for(int j=0;j<k;j++){
            cin>>a;
            graph[a][i+1] = 1;
        }
    }

    cin>>k;
    for(int i=0;i<k;i++){
        cin>>a;
        fill(vis, vis+maxn, 0);
        int out = bfs(a);
        cout<<out<<endl<<endl;
    }
    system("pause");
}

/*
7 3
3 2 3 4
0
2 5 6
2 3 1
2 3 4
1 4
1 5
2 2 6
*/