/*
 * @Author: xinyu Li
 * @Date: 2022-03-03 13:24:43
 * @LastEditTime: 2022-03-03 19:49:31
 * @Description: 
 * @FilePath: \helloworld\fuck\Sort\topologicSort.cpp
 * chaos is a ladder
 */
#include<bits/stdc++.h>
using namespace std;
int in[10], n;
vector<int> G[10];
int topo()
{
    priority_queue<int, vector<int>> q;  // queue也可以
    int cnt = 0;
    for(int i=0;i<n;i++){
        if(!in[i])
            q.push(i);
    }       
    while(!q.empty()){
        int top = q.front();
        q.pop();
        cnt++;
        for(int i=0;i<G[top].size();i++){
            int v = G[top][i];
            in[v]--;
            if(!in[v]) q.push(v);
        }
        G[top].clear();  //没必要，因为判断的是有向图是否是有向无环图，所以就算有环，也是零一条边到达top，不会是从top出去的边到达top
    }
    if(cnt == n) return 1;
    return 0;
}