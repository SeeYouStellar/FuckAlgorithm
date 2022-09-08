/*
 * @Author: xinyu Li
 * @Date: 2022-03-26 15:37:02
 * @LastEditTime: 2022-03-27 09:16:42
 * @Description:
 * @FilePath: \helloworld\luogu\P1606.cpp
 * chaos is a ladder
 * #include<bits/stdc++.h>
 * using namespace std;
 */
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

