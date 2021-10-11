//单源多目的最短路径问题：找到到每个点的最短路径
//Dijkstra算法是解单源最短路径的一种算法：它主要贪心为核心思想
//在Dijkstra的基础上增加分支限界的方法
//设定一个最短路径数组,数组的第i个元素记录当前到达i点的最短路径

#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
class Graph{
public:
    int price[100][100];//邻接矩阵
    int dist[100]; //到每个点的最近路径长度 ，相当于每个点都有一个bestp。在剪枝时，比较每个点的最佳值与当前这条路径的长度
    int n;
    int done[100];  //到这个点的最短路径是否已经找到
    int parent[100]; //记录每个节点的父节点 ，可以不断更新
};
class HeapNode{
public:
    //HeapNode* parent;  可能有多个id相同的HeapNode，所以用HeapNode记录父节点不正确
    int price;  //到该节点所经过路径长度  这里price == lb ，下界为以该节点为根节点的子树的最短路径长度
    int id;   //经过的节点编号
};

Graph G;
struct cmp{//优先队列若要自定义比较函数，只能是结构体内重载()符号
    bool operator()(HeapNode* &a, HeapNode* &b){return a->price > b->price;}
};
void AddNode
    (priority_queue<HeapNode*, vector<HeapNode*>, cmp>& pq,  int price, int id)
{
    HeapNode* newNode = new HeapNode();
    newNode->id = id;
    newNode->price = price;
    pq.push(newNode);
}
void ShortPath(int src)
{
    priority_queue<HeapNode*, vector<HeapNode*>, cmp> pq;
    HeapNode* E = new HeapNode();
    //init
    E->id = src;
    E->price = src;
    G.dist[src] = 0;
    G.done[src] = 1;
    int i = 1;
    while(i < G.n){
        for(int j=0;j<G.n;j++){  //扩展E节点
            if(G.price[E->id][j]!=-1 && E->id != j){ //剪枝条件1：两点之间不存在可达的路或扩展出的这个点就是正在扩展的节点
                int wt = E->price + G.price[E->id][j];  //当前路径到j的长度
                if(wt <= G.dist[j]){  //分支限界的剪枝条件。扩展节点E到j点的路径长度 大于 当前全局最佳到j点路径长度，那么就不可能是最优解。因为从j点到后面点的路径两者都是一样的。
                    G.dist[j] = wt;
                    G.parent[j] = E->id;
                    AddNode(pq, wt, j);
                }
            }
        }
        E = pq.top();
        pq.pop();
        G.done[E->id] = 1;
        i++;
    }
    for(int i=0;i<G.n;i++){
        vector<int> path;
        int par = i;
        while(par != -1){
            path.push_back(par);
            par = G.parent[par];
        }
        while(path.size()){
            cout<<path.back()<<"->";
            path.pop_back();
        }   
        cout<<": "<<G.dist[i]<<endl;
    }
}
int main()
{
    cin>>G.n;
    //init Graph
    for(int i=0;i<G.n;i++){
        for(int j=0;j<G.n;j++)
            cin>>G.price[i][j];
    }
    memset(G.dist, INT8_MAX, sizeof(int)*G.n);
    memset(G.done, 0, sizeof(int)*G.n);
    memset(G.parent, -1, sizeof(int)*G.n);
    ShortPath(0);

    for(int i=0;i<G.n;i++)
        cout<<G.dist[i]<<" ";
    system("pause");
}   
// 5
// 0 10 -1 30 100
// -1 0 50 -1 -1
// -1 -1 0 -1 10
// -1 -1 20 0 60
// -1 -1 -1 -1 0
