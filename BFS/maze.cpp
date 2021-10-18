//迷宫（maze）问题
#include<bits/stdc++.h>
using namespace std;
struct node{
public:
    int x;
    int y;
    int step;
}S, D, Node;

int graph[100][100]; //1代表能走的路,0代表障碍
int n, m; //列,行
bool inq[100][100] = {false};  //判断是否入队，并不是判断是否被访问
int X[4] = {0, 0, 1, -1};
int Y[4] = {1, -1, 0, 0};

bool test(int x, int y)
{
    if(x < 0 || x >= n || y < 0 || y >= m) return false;//越界
    else if(inq[x][y] == true) return false; //以搜索过
    else if(graph[x][y] == 1) return false; //障碍
    return true;
}

int BFS()
{
    queue<node> q;
    q.push(S);  //source
    inq[S.x][S.y] = true;
    while(!q.empty()){
        node top = q.front();
        q.pop();
        if(top.x == D.x && top.y == D.y) return top.step;
        for(int i=0;i<4;i++){
            int cx = top.x + X[i];
            int cy = top.y + Y[i];
            if(test(cx, cy)){
                Node.x = cx;
                Node.y = cy;
                Node.step = top.step + 1;
                inq[cx][cy] = true;
                q.push(Node);
            }
        }
    }
    return -1;
}
int main()
{
    //init S, T
    cin>>n>>m;
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++) cin>>graph[i][j];
    cin>>S.x>>S.y;
    S.step = 0;
    cin>>D.x>>D.y;
    int ans = BFS();
    cout<<ans;
    system("pause");
}
// 5 5
// 0 0 0 0 0
// 0 1 0 1 0
// 0 1 0 1 0
// 0 1 1 1 0
// 0 0 0 0 1
// 2 2 4 3
