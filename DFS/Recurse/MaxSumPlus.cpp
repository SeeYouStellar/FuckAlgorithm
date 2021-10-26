/*
 * @Author: xinyu Li
 * @Date: 2021-10-18 09:45:19
 * @LastEditTime: 2021-10-25 10:02:17
 * @Description: 
 * @FilePath: \helloworld\fuck\DFS\Recurse\MaxSumPlus.cpp
 * I am because you are
 */
//算法笔记p273

//子集树
/*
            O    i=0,n=0,cc=0,cal=0  每一层扩展子节点时首先判断下层的i和n是否符合要求。若不符合要求则不需要扩展,直接返回上一层
         1 / \ 0 选择或不选择    通过判断cc+arr[i+1]是否小于X来进行选择1/0
          O   O  第1层 
         / \ / \
        O  O O  O 
*/
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int X;  
int N;
int arr_N = 4;
int arr[5] = {0, 2, 3, 3, 4};
vector<int> out;
vector<int> choice;
int bestc = 0; //全局最优乘积
void backtrack(int i, int cc, int cal, int n)
{
    if(n == N){
        if(cc == X && cal > bestc){
            bestc = cal;
            choice = out;
        }
        return ;
    }
    if(n > N || cc > X || i > arr_N) return ;
    out.push_back(arr[i+1]);
    backtrack(i+1, cc+arr[i+1], cal+pow(arr[i+1], 2), n+1);
    out.pop_back();
    backtrack(i+1, cc, cal, n); 
}
int main()
{
    cin>>N>>X;
    backtrack(0, 0, 0, 0);
    cout<<bestc<<endl;
    for(int i=0;i<choice.size();i++)
        cout<<choice[i]<<" ";
    system("pause");
}