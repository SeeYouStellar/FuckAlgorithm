/*
 * @Author: xinyu Li
 * @Date: 2021-11-01 10:21:47
 * @LastEditTime: 2021-11-01 11:04:13
 * @Description: 
 * @FilePath: \helloworld\fuck\Graph\A1076\A1076(1).cpp
 * I am because you are
 */
#include<bits/stdc++.h>
using namespace std;
struct node {
    int id;
    int lev;
};
const int maxn = 1010;
int N, K, L, test[maxn] = {0};
vector<node> G[maxn];
int BFS(int s)
{
    queue<node> q;
    q.push(node{s, 0});
    int cnt = -1;
    test[s] = 1;
    while(!q.empty()){
        node top = q.front();
        q.pop();
        cnt++;
        if(top.lev == L) continue;
        for(int i=0;i<(G[top.id].size());i++){
            node next = G[top.id][i];
            next.lev = top.lev + 1;
            if(!test[next.id]){   //bfs设置test数组的目的是控制入队元素不重复
                test[next.id] = 1;
                q.push(next);
            }
        }
    }
    return cnt;
}
int main()
{
    cin>>N>>L;
    int n, a; 
    for(int i=1;i<=N;i++){
        cin>>n;
        for(int j=0;j<n;j++){
            cin>>a;
            node tmp;
            tmp.id = i;
            tmp.lev = 0;
            G[a].push_back(tmp);
        }
    }
    cin>>K;
    for(int i=0;i<K;i++){ 
        cin>>a;
        cout<<BFS(a)<<endl;
        memset(test, 0, sizeof(test));
    }
    system("pause");
}   