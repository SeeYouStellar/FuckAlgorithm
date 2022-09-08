### 普通0-1背包
#### 0-1背包问题的子问题 $dp[i][j]$:
>当有$i$件物品可供选择，背包剩余重量为$j$时的最大价值
#### 0-1背包问题的DP方程式:
$$
dp[i][j]=
\begin{cases}
max\{dp[i-1][j], dp[i-1][i-w[i]]+v[i]\}& \text{w[i]<=j}\\
dp[i-1][j]& \text{w[i]>j}
\end{cases}
$$



#### 我的理解是：
>轮到选择第$i$个物品时，每个$dp[i][j]$都是独立的状态，没有联系。如果有联系，计算$dp[i][j-w[i]]$时选择了第$i$个物品，那么$dp[i][j]$时就不能选择这个物品了。所以$dp[i][j]$这个状态要和没有选择第$i$个物品的状态进行比较,而我们定义的子问题是计算i件物品，那么只需与第$i-1$件物品的某些状态进行比较计即可（在状态方程式中已经说明）。
#### 代码：
```cpp
#include <bits/stdc++.h>
using namespace std;
int t, m, dp[1002];
int main()
{
    cin >> t >> m;
    vector<pair<int, int>> v(m + 1);
    for (int i = 1; i <= m; i++)
        cin >> v[i].first >> v[i].second;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= t; j++)
        {
            if (v[i].first < j)
                dp[j] = max(dp[i - 1][j], dp[i - 1][j - v[i].first] + v[i].second);
            else
                dp[j] = dp[i - 1][j]
        }

    cout << dp[m][t] << endl;
    system("pause");
}
```


### 完全0-1背包
>打破了0-1背包同一个$i$时，每个$dp[i][j]$相互没有联系这个约束，因为可以多次选择相同的物品，所以不仅要和$dp[i-1][i-w[i]]+v[i]$比，还要和
$dp[i][i-w[i]]+v[i]$比，那么自然就只要和$dp[i][i-w[i]]+v[i]$比就行（因为$dp[i][i-w[i]]$在计算时已经考虑了dp[i-1][i-w[i]]）。
#### 数组降维：
>道理就是上面说的，不需要物品这一维了
#### 代码：
```cpp
#include <bits/stdc++.h>
using namespace std;
long long t, m, dp[10000010];
int main()
{
	cin >> t >> m;
	vector<pair<int, int>> v(m + 1);
	for (int i = 1; i <= m; i++)
		cin >> v[i].first >> v[i].second;
	for (int i = 1; i <= m; i++)
		for (int j = v[i].first; j <= t; j++)
		{
			dp[j] = max(dp[j], dp[j - v[i].first] + v[i].second);
		}

	cout << dp[t] << endl;
	system("pause");
}
```
