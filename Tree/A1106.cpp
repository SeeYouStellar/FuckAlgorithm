#include<bits/stdc++.h>
using namespace std;
int hashtable[100010] = {0}, N, h[100010] = {0}; //h[i]记录第i个节点的深度，root深度为0
double P, r;
vector<int> Node[100010]; //树
int BFS(int root)
{
    queue<int> q;
    q.push(root);
    while(!q.empty()){
        int now = q.front();
        q.pop();

        if(!Node[now].size()) hashtable[h[now]]++;
        for(int i=0;i<Node[now].size();i++) {q.push(Node[now][i]);h[Node[now][i]] = h[now] + 1;}
    }
}
double pow(int n)
{
    double plus = P;
    for(int i=0;i<n;i++)
        plus *= (1+r);
    return plus;
}
int main()
{
    cin>>N>>P>>r;
    r /= 100;
    for(int i=0;i<N;i++){
        int n, child;
        cin>>n;
        if(n != 0){
            for(int j=0;j<n;j++){cin>>child;Node[i].push_back(child);}
        }else continue;
    }
    BFS(0);
    int i = 0;
    while(!hashtable[i])i++;
    printf("%.4f %d\n", pow(i), hashtable[i]);
    system("pause");
}
