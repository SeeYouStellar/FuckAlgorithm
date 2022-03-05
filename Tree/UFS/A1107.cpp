/*
 * @Author: xinyu Li
 * @Date: 2021-10-25 20:25:35
 * @LastEditTime: 2022-02-15 21:04:59
 * @Description: 
 * @FilePath: \helloworld\fuck\Tree\UFS\A1107.cpp
 * I am because you are
 */
#include <bits/stdc++.h>
using namespace std;
//Union_ find set :并查集是为了将不同元素分成多个集合的数据结构。实际上就是一个father数组。并查集靠Union_操作形成不同的集合。
int N, K, father[1010], course[1010];
int find(int x)
{
    if(x == father[x]) return x;
    father[x] = find(father[x]);
    return father[x];
}
void Union_(int a, int b)
{
    int fa = find(a);
    int fb = find(b);
    if(fa != fb)
        father[fa] = fb;
}
void init()
{
    for(int i=1;i<=N;i++){
        father[i] = i;
    }
}
int main()
{
    cin>>N;
    int a;
    init();
    getchar();
    for(int i=0;i<N;i++){
        scanf("%d: ", &K);
        
        for(int j=0;j<K;j++){
            cin>>a;
            if(!course[a]) course[a] = i+1;
            else Union_(course[a], i+1);
        }
    }
    for(int i=1;i<=N;i++) find(i);        //保证每个集合的father[x]都只有一个,在find过程中调整father[x]
    vector<int> v;      
    int cc = 0;                           //每个集合拥有唯一father后，只要遍历每个father[x]就可以找到该集合的元素
    for(int i=1;i<=N;i++){
        if(father[i] == i){
            cc++;
            int count = 0;
            for(int j=1;j<=N;j++){
                if(father[j] == i)
                    count++;
            }
            v.push_back(count);
        }
    }
    cout<<cc<<endl;
    sort(v.rbegin(), v.rend());
    cout<<v[0];
    for(int i=1;i<v.size();i++) cout<<" "<<v[i];
    system("pause");
}