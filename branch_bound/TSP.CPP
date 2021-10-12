// //旅行商问题：
// //给定一张n个城市的完全图（任意两个节点之间都有边），从起点出发，找到一条路径经过每个城市一次且有且一次，最后回到起始点，并且这条路径的花费最少
// //ub:
// //lb = 以确定费用+未确定的最小值
// //cc:当前路径的费用
// //bestc:最优值，即当前最短回路的费用
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
class Graph {
public:
    int price[100][100];
    int n;
    int priceMin[100];
}G;
class HeapNode{
public:
    int id;
    int cc;
    int lb;
    HeapNode* par;  //父节点：相当于储存一条路径
    int lev;
};
int bestc;
struct cmp{
    bool operator()(HeapNode* & a, HeapNode* & b){
        return a->lb > b->lb;
    }
};
int lbound(int id, int lb, int next)
{
    lb -= G.priceMin[id];
    lb += G.price[id][next];
    return lb;
}

void AddNode(priority_queue<HeapNode*, vector<HeapNode*>, cmp>& pq, int cc, int lb, int id, HeapNode* par)
{
    HeapNode* h = new HeapNode();
    h->cc = cc;
    h->id = id;
    h->par = par;
    h->lb = lb;
    h->lev = par->lev+1;
    pq.push(h);
}
bool found(HeapNode* prev, int curr)
{
    do{
        if(prev->id == curr)
            return true;
        prev = prev->par;
    }while(prev != NULL);
    return false;
}
void ShortPath()
{
    priority_queue<HeapNode*, vector<HeapNode*>, cmp> pq;
    HeapNode* E = new HeapNode();
    E->cc = 0;
    E->lb = 0;
    for(int i=0;i<G.n;i++)
        E->lb += G.priceMin[i];
    E->id = 0;  //第0个城市为起点
    E->par = NULL;
    E->lev = 1;

    int id = 0, cc = 0, lb = E->lb, lev = 1;
    bestc = INT8_MAX;
    while(cc != lb){
        cout<<bestc<<endl;
        if(lev < G.n-1){
            for(int j=1;j<G.n;j++){
                if(lbound(id, lb, j) < bestc && !found(E, j)){
                    AddNode(pq, cc+G.price[j][id], lbound(id, lb, j), j, E);
                    //cout<<cc+G.price[j][id]<<" "<<lbound(id, lb, j)<<endl;
                }
            }
        }
        else if(lev == G.n-1){  //当到达叶节点的父节点的父节点时 ，因为只要知道父节点的父节点产生了什么子节点（即选了哪条路），就可以知道父节点到叶节点选哪条路（即x城市 到 起始点的路不用选额只有一条）
            for(int j=1;j<G.n;j++){   
                //判断cc+父节点的父节点到父节点+父节点到叶节点的路径长度 和 cc+父节点到叶节点 是否满足小于bestc这个条件，若满足则直接生成叶节点（或者说将两个节点合并为一个节点，减少了一个节点的创建），若不满足则
                if(lb-G.priceMin[id]-G.priceMin[j]+G.price[id][j]+G.price[j][0] < bestc && !found(E, j)){  //lbound(id, lb, j) < bestc： 只要lb-G.priceMin[id]-G.priceMin[j]+G.price[id][j]+G.price[j][0] < bestc满足，则一定满足，因为lbound计算时选的都是每个城市的最小出边
                    bestc = cc+G.price[id][j]+G.price[j][0];
                    AddNode(pq, bestc, lb-G.priceMin[id]-G.priceMin[j]+G.price[id][j]+G.price[j][0], j, E);
                    //cout<<"  11111  "<<bestc<<" "<<lb-G.priceMin[id]-G.priceMin[j]+G.price[id][j]+G.price[j][0]<<endl; 
                }
            }   
        }
        E = pq.top();
        pq.pop();
        cc = E->cc;
        lb = E->lb;
        id = E->id;
        lev = E->lev;
        cout<<id<<" "<<cc<<" "<<lb<<" "<<lev<<endl;
    }
}
int main()
{
    cin>>G.n;
    for(int i=0;i<G.n;i++){
        int temp = INT8_MAX;
        for(int j=0;j<G.n;j++){
            cin>>G.price[i][j];
            if(G.price[i][j] < temp && G.price[i][j] != 0)
                temp = G.price[i][j];
        }
        G.priceMin[i] = temp;
    }
    ShortPath();
    cout<<bestc;
    system("pause");
}
/*
// 4 
// 0 30 6 4
// 30 0 5 10 
// 6 5 0 20 
// 4 10 20 0

// 5 
// 0 3 1 5 8
// 3 0 6 7 9
// 1 6 0 4 2
// 5 7 4 0 3
// 8 9 2 3 0
// */

