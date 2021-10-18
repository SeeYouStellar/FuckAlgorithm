//组合数的输出 输入5、3，输出12345中随便3个数，全部输出
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int n;
int r;
stack<int> s;
vector<int> v;

void recurse(int i, int a)
{
    if(i > n){
        if(a == r){
            for(int j=0;j<r;j++)
                cout<<v[j]<<" ";
            cout<<endl;
        }
        return ;
    }
    if(a <= r){      //在递归退出条件if语句下的条件语句为剪枝操作。减去所有以a > r节点为根的树
        v.push_back(i);
        recurse(i+1, a+1);
        v.pop_back();
        recurse(i+1, a);
    }
    // temp.push_back(i);
    // recurse(i+1, a+1);
    // temp.pop_back();
}
int main()
{
    cin>>n>>r;
    recurse(1, 0);
    system("pause");
}