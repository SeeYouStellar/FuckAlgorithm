/*
 * @Author: xinyu Li
 * @Date: 2021-10-18 09:45:19
 * @LastEditTime: 2021-10-25 09:58:33
 * @Description: 
 * @FilePath: \helloworld\fuck\DFS\Recurse\Combination.cpp
 * I am because you are
 */
//组合数的输出 输入5、3，输出12345中随便3个数，全部输出
#include<iostream>
#include<vector>
using namespace std;
int n;
int r;
vector<int> v;

void recurse(int i, int a)
{
    if(i == n+1){
        if(a == r){
            for(int j=0;j<r;j++)
                cout<<v[j]<<" ";
            cout<<endl;
        }
        return ;
    }
    if(a > r) return;  //在递归退出条件if语句下的条件语句为剪枝操作。减去所有以a > r节点为根的树
    v.push_back(i);
    recurse(i+1, a+1);
    v.pop_back();
    recurse(i+1, a);
}
int main()
{
    cin>>n>>r;
    recurse(1, 0);
    system("pause");
}