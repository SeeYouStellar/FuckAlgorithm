//子集树的根节点代表搜索还未开始，根节点所在层i=0，第0层和第1层之间的子集树左节点代表选择第1个物品，右节点代表不选择这个物品
/*
            O    第0层
           / \   第1个物品，在物品数组中索引为i=0
          O   O  第1层，两个节点若加入到pq中时，层序号为1

*/
//分支限界法搜索到叶节点时，up == cp，左叶节点的up等于父节点的up,父节点的up=cp+w[i]=左节点cp,故左节点cp==up
/*
为什么当pq弹出的节点时是叶节点时，就找到了最优解？
假设弹出的叶节点的cp小于全局bestp，那么一定存在一个另外的节点的cp=bestp，又所有节点的up>=cp，那么up>=bestp,而pq以up为优先级，所以如果叶节点不是最优解，那么它就不会被弹出
*/
#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
class Object{
public:
    int w;
    int p;
    int id;
    double per;  //单位价格
};
class HeapNode{
public:
    HeapNode* parent;
    double up; //上界
    int weight;//当前重量
    int price;//当前价格
    int level;
    int lchild;//是否是父节点的左子节点
};
Object obj[10000];
int path[10000];
int n, c, bestp;
struct cmp{
    bool operator()(HeapNode* &a, HeapNode* &b)  //降序
    {
        return a->up < b->up;
    }   
};
bool comp(const Object& a, const Object& b)  //降序
{
    return a.per > b.per;
}
void AddHeapnode
    (priority_queue<HeapNode* ,vector<HeapNode*>, cmp>& pq, HeapNode* parent, double up, int w, int p, int lev, int lchild)
{
    HeapNode* newp = new HeapNode;
    newp->level = lev;  //该节点在子集树中的层次，从0开始
    newp->parent = parent;
    newp->price = p;
    newp->up = up;
    newp->weight = w;
    newp->lchild = lchild; 
    pq.push(newp);
}
int bound(int i, int cw, int cp)
{
    int leftc = c - cw;
    int up = cp;
    while(leftc >= 0 && i < n){
        leftc -= obj[i].w;
        up += obj[i].p;
        i++;
    }
    if(leftc < 0){
        up -=obj[i-1].p;
        up += (obj[i-1].w+leftc)*obj[i-1].per;
    }
        
    return up;
}
void maxprice()
{
    priority_queue<HeapNode *, vector<HeapNode *>, cmp> pq;
    HeapNode* E = NULL;
    int i = 0, cw = 0, cp = 0, up = bound(0, 0, 0);
    bestp = 0;
    while(i < n){  //当搜索到子集树第i层的节点时代表找到最优解   （分支限界法目标找到一个最优解即可）
        int wt = cw + obj[i].w;  //获取左子树的重量（即选择i=0的物品后的重量）
        if(wt <= c){   
            if(bestp < cp + obj[i].p)
                bestp = cp + obj[i].p;
            AddHeapnode(pq, E, up, wt, cp+obj[i].p, i+1, 1);  //左子节点的上界与父节点的上界一样。且还该节点在子集树中位于第i+1层
        }
        up = bound(i+1, cw, cp);//这一层的右子节点的up要从下一层的物品开始算起  ，这里带入的当前重量是cw，而不是wt，代表这一层的物品没有选择
        if(up >= bestp)
            AddHeapnode(pq, E, up, cw, cp, i+1, 0);
        E = pq.top();  //从pq中取下一个扩展节点
        pq.pop();  //将该节点删去
        i = E->level;  //下一个i可能不是i++
        cw = E->weight;  
        cp = E->price;
        up = E->up;
        cout<<cw<<" "<<cp<<" "<<up<<" "<<i<<" "<<E->lchild<<endl;   //每次弹出的节点的信息，弹出不代表就是最后的路径上的节点
    }
    for(int i=n-1;i>=0;i--){
        path[i] = E->lchild;
        E = E->parent;
    }
}
int main()
{
    cin>>n>>c;
    for(int i=0;i<n;i++){
        int W, P;
        cin>>P>>W;
        obj[i].p = P;
        obj[i].w = W; 
        obj[i].per = 1.0*P/W;
        obj[i].id = i;
    }
    sort(obj, obj+n, comp);
    // for(int i=0;i<n;i++){
    //     cout<<obj[i].p<<" "<<obj[i].w<<endl;
    // }
    maxprice();
    cout<<"bestp"<<bestp<<endl;
    for(int i=0;i<n;i++)
        cout<<path[i]<<" ";
    system("pause");
}
// 4 10
// 40 4
// 42 7
// 25 5
// 12 3


//网上找的代码
// //分支限界法：求最大值定义upper_bound(ub)，代表树的某一条路径理想最大值。
// //当ub小于当前最大值时就不需要考虑以该节点为根节点的树
// //在搜索的过程中也可以进行适当的剪枝
// #include <bits/stdc++.h>
// using namespace std; 
// class Object   //物品类
// {
// public:
//     int id;
//     int weight;
//     int price;
//     float d;  //单位质量的价格
// };
// class MaxHeapQNode
// {
// public:
//     MaxHeapQNode *parent;
//     int lchild;
//     int upprofit;
//     int profit;
//     int weight;
//     int lev;
// };
// //pq的比较类 
// struct cmp   
// {
//     bool operator()(MaxHeapQNode *&a, MaxHeapQNode *&b) const
//     {
//         return a->upprofit < b->upprofit;
//     }
// };

// bool compare(const Object &a, const Object &b)   //标准库sort函数需要自己添加比较函数  using function as comp
// {
//     return a.d >= b.d;
// }
// /*using object as comp
// struct compare{
//     bool operator()(Object &a, Object &b){return a.d >= b.d;}
// };
// */
// int n;
// int c;
// int cw;
// int cp;
// int bestp;
// Object obj[100];
// int bestx[100];
// void InPut()
// {
//     scanf("%d %d", &n, &c);
//     for(int i = 1; i <= n; ++i)  //从i=1开始
//     {
//      scanf("%d %d", &obj[i].price, &obj[i].weight);
//      obj[i].id = i;
//      obj[i].d = 1.0 * obj[i].price / obj[i].weight;
//     }
 
//     sort(obj + 1, obj + n + 1, compare);
// //    for(int i = 1; i <= n; ++i)
// //        cout << obj[i].d << " ";
// //    cout << endl << "InPut Complete" << endl;
// }
// int Bound(int i)
// {
//     int tmp_cleft = c - cw;      //算up时都是右节点时算，即不选当前物品，所以选用上一层的cw。
//     int tmp_cp = cp;
//     while(tmp_cleft >= obj[i].weight && i <= n)
//     {
//         tmp_cleft -= obj[i].weight;
//         tmp_cp += obj[i].price;
//         i++;
//     }
//     if(i <= n)
//     {
//         tmp_cp += tmp_cleft * obj[i].d;
//     }
//     return tmp_cp;
// }
// void AddAliveNode(priority_queue<MaxHeapQNode *, vector<MaxHeapQNode *>, cmp> &q, MaxHeapQNode *E, int up, int wt, int curp, int i, int ch)
// {
//     MaxHeapQNode *p = new MaxHeapQNode;    //父节点
//     p->parent = E;
//     p->lchild = ch;
//     p->weight = wt;
//     p->upprofit = up;
//     p->profit = curp;
//     p->lev = i + 1;    //在子集树中的层序号
//     q.push(p);
// //    cout << "加入点的信息为 " << endl;
// //    cout << "p->lev = " << p->lev << " p->upprofit = " << p->upprofit << " p->weight =  " << p->weight << " p->profit =  " << p->profit << endl;
// }
// void MaxKnapsack()
// {
//     priority_queue<MaxHeapQNode *, vector<MaxHeapQNode *>, cmp > q; // 大顶堆
//     MaxHeapQNode *E = NULL;
//     cw = cp = bestp = 0;
//     int i = 1;
//     int up = Bound(1); //Bound(i)函数计算的是i还未处理时候的上限值
//     while(i != n + 1)
//     {
//         int wt = cw + obj[i].weight;
//         if(wt <= c)
//         {
//             if(bestp < cp + obj[i].price)
//                 bestp = cp + obj[i].price;
//             AddAliveNode(q, E, up, cw + obj[i].weight, cp + obj[i].price, i, 1);
//         }
//         up = Bound(i + 1); //注意这里 up != up - obj[i].price而且 up >= up - obj[i].price
//         if(up >= bestp) //注意这里必须是大于等于
//         {
//             AddAliveNode(q, E, up, cw, cp, i, 0);
//         }
//         E = q.top();
//         q.pop();
//         cw = E->weight;
//         cp = E->profit;
//         up = E->upprofit;
//         i = E->lev;
//     }
//     //构造解
//     for(int j = n; j > 0; --j)
//     {
//         bestx[obj[E->lev - 1].id] = E->lchild;
//         E = E->parent;
//     }
// }
// void OutPut()
// {
//     printf("最优装入量为 %d\n", bestp);
//     printf("装入的物品为 \n");
//     for(int i = 1; i <= n; ++i)
//         if(bestx[i] == 1)
//           printf("%d ", i);
// }
// int main()
// {
//     InPut();
//     MaxKnapsack();
//     OutPut();
//     system("pause");
// }
// // 4 10
// // 40 4
// // 42 7
// // 25 5
// // 12 3

