/*
 * @Author: xinyu Li
 * @Date: 2021-10-25 18:56:09
 * @LastEditTime: 2021-10-25 20:24:44
 * @Description: 
 * @FilePath: \helloworld\fuck\Tree\UFS\A1107.cpp
 * I am because you are
 */
#include<bits/stdc++.h>
using namespace std;
//union find set :并查集是为了将不同元素分成多个集合的数据结构。实际上就是一个father数组。并查集靠Union操作形成不同的集合。
int N, father[1000];
int find2(int node) //递归写法
{
    if(father[node] != node)
        father[node] = find2(father[node]); 
    return father[node];
}
void Union(int a, int b)
{
    int fa = find2(a);
    int fb = find2(b);
    if(fa != fb)
        father[fb] = fa;
}
int find(int node)
{
    int tmp = node;
    while(father[node] != node) node = father[node];
    while(tmp != node) {father[tmp] = node;tmp = father[tmp];}
    return node;
}

int main()
{
    cin>>N;
    for(int i=1; i<=N;i++) father[i] = i;
    Union(1, 2);
    Union(2, 3);
    for(int i=1; i<=N;i++) cout<<father[i]<<" ";
    system("pause");
}