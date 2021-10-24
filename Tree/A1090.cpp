//只需要计算出每个节点的深度即可，因为每层节点的深度是一样的。
//子节点的深度是父节点的深度加1，所以用DFS

#include<bits/stdc++.h>
using namespace std;
int N, Count[100010];
vector<int> count_[100010];
double P, r;
struct node{
    int level;
    vector<int> child;
}Node[100010];
void DFS(int root)
{   
    for(int i=0;i<Node[root].child.size();i++){
        Node[Node[root].child[i]].level = Node[root].level + 1;
        DFS(Node[root].child[i]);
    }
}
int BFS(int root)  //另一种遍历的方法
{   
    queue<int> q;
    q.push(root);
    int tmp = root, level = 0;
    
    while(!q.empty()){
        int top = q.front();
        q.pop();
        if(top == tmp){
            if(!Node[top].child.size()){
                continue;
            }
            level++;
            tmp = Node[top].child[Node[top].child.size()-1];
            count_[level].push_back(0);
        }
        for(int i=0;i<Node[top].child.size();i++){
            q.push(Node[top].child[i]);
            count_[level].push_back(Node[top].child[i]);
        }
    }
    return level;
}
double pow(int n)
{   
    double p = P;
    for(int i=0;i<n;i++) p *= (1+r);
    return p;
}
int Root;
int main()
{
    cin>>N>>P>>r;
    r /= 100;
    int sup;
    vector<int> RootSon;
    for(int i=0;i<N;i++){
        cin>>sup;
        if(sup == -1) {Root = i;continue;}
        Node[sup].child.push_back(i);
    }
    Node[Root].level = 0;
    DFS(Root);
    int level = 0, count = 0;
    for(int i=0;i<N;i++){
        if(Node[i].level > level) {level = Node[i].level;count = 1;}
        else if(Node[i].level == level) count++;
    }
    // count_[0].push_back(1);
    // int level = BFS(Root);
    // printf("%.2f %d", pow(level), count_[level].size());
    printf("%.2f %d", pow(level), count);
    cout<<endl;
    system("pause");
}