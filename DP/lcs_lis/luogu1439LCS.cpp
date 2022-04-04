/*
 * @Author: xinyu Li
 * @Date: 2022-03-28 12:26:33
 * @LastEditTime: 2022-03-28 16:47:18
 * @Description: 
 * @FilePath: \helloworld\luogu\P1439.cpp
 * chaos is a ladder
 * #include<bits/stdc++.h>
 * using namespace std;
 */

#include<bits/stdc++.h>
using namespace std;

/* O(n*n)  lCS 最大公共子序列 和最大公共子串不同，子串必须要连续，子序列可以跳*/
// int n, a[100010], b[100010], dp[10010][10010];
// int main() {
//     cin>>n;
//     for(int i=1;i<=n;i++)
//         cin>>a[i];
//     for(int i=1;i<=n;i++)
//         cin>>b[i];
//     for(int i=1;i<=n;i++){
//         for(int j=1;j<=n;j++){
//             if(a[i]==b[j]) dp[i][j] = dp[i-1][j-1]+1;
//             else dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
//         }
//     }
//     printf("%d\n", dp[n][n]);
//     system("pause");
// }

//最大递增子序列
//1. O(n*n) dp[i]=max{dp[j]|s[j]<s[i], 0<=j<i}+1 , dp[0]=0; 
//2. O(nlogn) LIS  https://blog.csdn.net/LxcXingC/article/details/81238008* 
// const int maxn = 100010;
// int n, dp[maxn], a[maxn];
// int main()
// {
//     cin>>n;
//     for(int i=1;i<=n;i++)
//         cin>>a[i];
//     dp[0] = 0;
//     int len = 0;
//     for(int i=1;i<=n;i++){
//         if(a[i] > dp[len])
//             dp[++len] = a[i];
//         else *lower_bound(dp, dp + len, a[i]) = a[i];//二分查找比s[i]大的第一个数并替换
//     }
//     cout<<len<<endl;
//     system("pause");
// }
//最大递增子串 这个没必要讨论  O(n)
//dp[i]=if s[i-1]<s[i], dp[i-1]+1;
//     =1, others;



/* O(nlogn) LCS*/
const int maxn = 100010;
int n, dp[maxn], a[maxn], b[maxn];
map<int, int> m;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        m[a[i]] = i;
    }
    for(int i=1;i<=n;i++)
        cin>>b[i];  
    dp[0]=0;
    int len=0; 
    for(int i=1;i<=n;i++){
        if(m[b[i]]>dp[len])
            dp[++len] = m[b[i]];
        else
            *lower_bound(dp, dp+len, m[b[i]]) = m[b[i]];  //找到不小于目标值的第一个元素，内部是用二分实现
    }
    cout<<len<<endl;
    system("pause");
}