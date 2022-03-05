/*
 * @Author: xinyu Li
 * @Date: 2021-10-18 15:56:20
 * @LastEditTime: 2022-02-15 12:21:46
 * @Description: 
 * @FilePath: \helloworld\fuck\Tree\A1053.cpp
 * I am because you are
 */
//要按照路径的字典序排列输出  
//路径：DFS
//树：静态数组
//字典序：sort(pointer begin, pointer end, cmp)
//对序列的排序输出思路不一定是用优先队列存储序列，可以是sort函数，对序列进行排序输出，写法与优先队列类似，可以自己定义比较函数（不用写struct来重载，只需要写一个cmp函数）
#include<bits/stdc++.h>
using namespace std;
struct Node{
    int weight;
    vector<int> child;
}tree[110];
int N, M, S;
vector<int> tmp;
vector<vector<int>> ans;
void dfs(int root, int sum)
{
    if(!tree[root].child.size() && sum == S){
        ans.push_back(tmp);
    }
    for(int i=0; i<tree[root].child.size();i++){
        tmp.push_back(tree[tree[root].child[i]].weight);
        dfs(tree[root].child[i], sum+tree[tree[root].child[i]].weight);
        tmp.pop_back();
    }
}
bool cmp(int a, int b)
{
    
    return tree[a].weight > tree[b].weight;
}
int main()
{
    cin>>N>>M>>S;
    for(int i=0; i<N; i++)
        cin>>tree[i].weight;
    int id, k, a;
    for(int i=0; i<M; i++){
        cin>>id>>k;
        for(int j=0;j<k;j++){
            cin>>a;
            tree[id].child.push_back(a);
        }
        sort(tree[id].child.begin(), tree[id].child.end(), cmp);
    }
    dfs(0, tree[0].weight);
    if(S >= tree[0].weight){
        for(int i=0;i<ans.size();i++){
            cout<<tree[0].weight;
            for(int j=0;j<ans[i].size();j++)
                cout<<" "<<ans[i][j];
            cout<<endl;
        }
    }
    
    system("pause");
}
/*
20 9 24
10 2 4 3 5 10 2 18 9 7 2 2 1 3 12 1 8 6 2 2
00 4 01 02 03 04
02 1 05
04 2 06 07
03 3 11 12 13
06 1 09
07 2 08 10
16 1 15
13 3 14 16 17
17 2 18 19
*/