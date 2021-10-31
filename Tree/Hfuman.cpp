/*
 * @Author: xinyu Li
 * @Date: 2021-10-27 08:38:57
 * @LastEditTime: 2021-10-27 08:48:33
 * @Description: 
 * @FilePath: \helloworld\fuck\Tree\Hfuman.cpp
 * I am because you are
 */
//模拟哈夫曼树形成的过程 ,开始时有N个树，这些树只有根节点，将他们放入优先队列中，每次取出这些根节点中的两个最小值，相加后的值构建一个根节点左右节点为相加的两个值，
//这样就又形成一棵树，将根节点继续放入优先队列。循环这个操作，直到队列中只有一个根节点
#include<bits/stdc++.h>
using namespace std;
int N;
priority_queue<int, vector<int>, greater<int>> pq;
int main()
{
    int a;
    cin>>N;
    for(int i=0;i<N;i++){cin>>a;pq.push(a);}
    while(pq.size() > 1){
        int a = pq.top();
        pq.pop();
        a += pq.top();
        pq.pop();
        pq.push(a);
    }
    cout<<pq.top()<<endl;
    system("pause");
}

