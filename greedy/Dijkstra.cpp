//不用优先队列,不用类的版本
#include<iostream>
#include<cstring>
using namespace std;
int dist[100];
int done[100];
int Prev[100];
void ShortPath(int price[100][100], int src, int n)
{   
    dist[src] = 0;
    int i = 0;
    int E = src;//起始点
    while(i < n){  //循环n次 ，每次都得出一个点的最短路径
        for(int j=0;j<n;j++){ //扩展节点
            if(j != E && price[E][j] != -1 && dist[E]+price[E][j] < dist[j]){
                dist[j] = dist[E]+price[E][j];
                Prev[j] = E;
            }
        }
        done[E] = 1;
        int temp = INT8_MAX;
        for(int j=0;j<n;j++){     //贪心选择
            if(dist[j] < temp && !done[j]){
                temp = dist[j];
                E = j;
            }
        }
        i++;
    }
}
int main()
{
    int n;
    int price[100][100];
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cin>>price[i][j];
    }   
    memset(dist, INT8_MAX, sizeof(int)*n);
    memset(done, 0, sizeof(int)*n);
    memset(Prev, -1, sizeof(int)*n);
    ShortPath(price, 0, 5);
    for(int i=0;i<n;i++){
        
        cout<<dist[i]<<" ";
    }
    system("pause");    
}

// 5
// 0 10 -1 30 100
// -1 0 50 -1 -1
// -1 -1 0 -1 10
// -1 -1 20 0 60
// -1 -1 -1 -1 0
