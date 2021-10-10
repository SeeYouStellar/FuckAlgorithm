// #include <iostream>
// using namespace std;
// const int maxn = 10000;
// int a[maxn];
// bool flag[maxn] = { false };
// //递归法
// void backtrack(int index, int n, int r) {
// 	if (index == r) {
// 		for (int i = 0; i < r; i++)
// 			cout<<a[i]<<' ';
// 		cout<<endl;
// 		return;
// 	}
// 	for (int i = 0; i < n; i++) { //在多叉树的同一个节点处，其子节点按字典序（从小到大）赋值，比如1->2，1->3。
// 		if (flag[i] == false) {   //flag[i]=true or false 代表 数字（i+1）是否已经在该次序列中使用
// 			a[index] = i + 1;   	  //当i+1这个数可用时，则将其加入a数组
// 			flag[i] = true;       //
// 			backtrack(index + 1, n, r);
// 			flag[i] = false;
// 		}
// 	}
// }
// //非递归法
// void func()
// {

// }
// int main() {
// 	int n, r;
// 	while (scanf("%d%d", &n, &r) != EOF)
// 		backtrack(0, n, r);
// 	return 0;
// }

#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

void permutation(int n, int m)
{
    vector<int> combine;
    stack<int> buf;
    bool pop = false;
    int top;

    buf.push(1);
    combine.push_back(1);

    while (buf.size())
    {
        if (combine.size() == m)
        {
            for (int i = 0; i < m; ++i)
            {
                printf("%d", combine[i]);
                if (i != m - 1)
                    printf(" ");
            }
            printf("\n");
            pop = true;
        }

        top = buf.top() + 1;
        if (top == n + 1)
        {
            pop = true;
            buf.pop();
            combine.pop_back();
            continue;
        }

        if (pop)
        {
            buf.pop();
            combine.pop_back();
            pop = false;
        }

        if (top <= n)
        {
            buf.push(top);
            combine.push_back(top);
        }
    }

}

int main()
{
#ifdef _DEBUG
    freopen("data.txt", "r+", stdin);
#endif // _DEBUG

    int n, m, PS = 0;

    while (cin >> n >> m)
    {
        permutation(n, m);
    }



    return 0;
}
/**************************************************************
    Problem: 5973
    User: Sharwen
    Language: C++
    Result: 升仙
    Time:94 ms
    Memory:1720 kb
****************************************************************/

