/*
 * @Author: xinyu Li
 * @Date: 2021-10-18 09:45:19
 * @LastEditTime: 2022-02-06 09:29:56
 * @Description: 
 * @FilePath: \helloworld\fuck\DFS\Recurse\01bag.cpp
 * I am because you are
 */
#include<iostream>
using namespace std;
int arr[5] = {0, 0, 0, 0, 0};
int a[5] = {0, 0 ,0, 0, 0};  //用来记录二叉树的某一条路径上的选择情况，当到大递归边界时判断这一条路径上得到的价值是否比全局最大值大，若是则将数组a复制给arr。
int w[5] = {3, 5, 1, 2, 2};
int v[5] = {4, 5, 2, 1, 3};
int T = 8;
int n = 5;
int maxv = 0;
void DFS(int sumw, int sumv, int index)
{
    if(index == n){
        if(maxv < sumv){
            maxv = sumv;
            memcpy(arr, a, 5*sizeof(int));  // memcpy(destin, sourse, 要复制的字节数) 这里sizeof(arr)也行
        } 
        return ;
    }
    if(sumw + w[index] <= T){
        a[index] = 1;
        DFS(sumw+w[index], sumv+v[index], index+1);
    }
    a[index] = 0;
    DFS(sumw, sumv, index+1);
}
int main()
{
    DFS(0, 0 ,0);
    for(int i=0;i<n;i++)       //输出选择的物品
        cout<<arr[i]<<' ';        
    cout<<"\n"<<maxv<<endl;  
    system("pause");
}