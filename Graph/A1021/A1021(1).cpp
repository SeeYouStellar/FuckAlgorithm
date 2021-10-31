/*
 * @Author: xinyu Li
 * @Date: 2021-10-30 15:22:23
 * @LastEditTime: 2021-10-30 15:48:03
 * @Description: 
 * @FilePath: \helloworld\fuck\Graph\A1021\A1021(1).cpp
 * I am because you are
 */

#include<bits/stdc++.h>
using namespace std;

const int N = 110;
vector<int> G[N]; //邻接表

bool isRoot[N]; //记录每个结点是否作为某个集合的根结点
int father[N];  //并查集
int findFather(int x)
{
    int a = x;
    while (x != father[x])
    {
        x = father[x];
    }
    //路径压缩
    while (a != father[a])
    {
        int z = a;
        a = father[a];
        father[z] = x;
    }
    return x;
}
void Union(int a, int b)
{ //合并a和b所在的集合
    int faA = findFather(a);
    int faB = findFather(b);
    if (faA != faB)
    {
        father[faA] = faB;
    }
}
void init(int n)
{ //并查集初始化
    for (int i = 1; i <= n; i++)
    {
        father[i] = i;
    }
} 
int calBlock(int n)    //巧妙
{ //计算连通块个数
    int Block = 0;
    for (int i = 1; i <= n; i++)
    {
        isRoot[findFather(i)] = true; //i的根节点是findFather(i)
    }
    for (int i = 1; i <= n; i++)
    {
        Block += isRoot[i]; //累加根结点个数
    }
    return Block;
}
int maxH = 0;          //最大高度
vector<int> temp, ans; //temp临时存放dfs的最远结点结果，ans保存答案

//dfs函数,u为当前访问结点编号，height为当前树高，pre为u的父节点
void dfs(int u, int height, int pre)
{
    if (height > maxH)
    {                      //获得了更大的树高
        temp.clear();      //清空temp
        temp.push_back(u); //将当前结点u加入temp中
        maxH = height;     //更新最大树高
    }
    else if (height == maxH)
    {
        temp.push_back(u); //加入当前结点到temp中
    }
    for (int i = 0; i < G[u].size(); i++)
    { //遍历u的所有子节点
        //由于邻接表中存放无向图，因此需要跳过回去的边
        if (G[u][i] == pre)
            continue;
        dfs(G[u][i], height + 1, u); //访问子节点
    }
}

int main()
{
    int a, b, n;
    scanf("%d", &n);
    init(n);
    for (int i = 1; i < n; i++)
    {
        scanf("%d%d", &a, &b);
        G[a].push_back(b); //边a->b
        G[b].push_back(a); //边b->a
        Union(a, b);       //合并a和b所在的集合
    }
    int Block = calBlock(n); //计算集合数目
    if (Block != 1)
    { //不止一个连通块
        printf("Error: %d components\n", Block);
    }
    else
    {
        dfs(1, 1, -1);      //从1号结点开始dfs，初始高度为1
        ans = temp;         //temp为集合A，赋值给ans
        dfs(ans[0], 1, -1); //从任意一个根节点开始遍历
        for (int i = 0; i < temp.size(); i++)
        {
            ans.push_back(temp[i]); //此时temp为集合b，将其加到ans中
        }
        sort(ans.begin(), ans.end()); //按编号从小到大排序
        printf("%d\n", ans[0]);
        for (int i = 1; i < ans.size(); i++)
        {
            if (ans[i] != ans[i - 1])
            { //重复编号不输出
                printf("%d\n", ans[i]);
            }
        }
        //        dfs(1, 1, -1);//从1号结点开始dfs，初始高度为1
        //        set<int> setofRoot;
        //        for (int i = 0; i < temp.size(); i++) {
        //            setofRoot.insert(temp[i]);
        //        }
        //        dfs(temp[0], 1, -1);
        //        for (int i = 0; i < temp.size(); i++) {
        //            setofRoot.insert(temp[i]);
        //        }
        //        for (set<int>::iterator it = setofRoot.begin(); it != setofRoot.end(); it++) {
        //            printf("%d\n", *it);
        //        }
    }
    return 0;
}