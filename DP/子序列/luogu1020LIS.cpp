/*
 * @Author: xinyu Li
 * @Date: 2022-03-29 09:38:27
 * @LastEditTime: 2022-03-29 12:23:41
 * @Description:
 * @FilePath: \helloworld\luogu\P1020.cpp
 * chaos is a ladder
 * #include<bits/stdc++.h>
 * using namespace std;
 */

// /*
// 2、对于问二求整个数列的最长上升子序列即可。证明如下：

// （1）假设打导弹的方法是这样的：取任意一个导弹，从这个导弹开始将能打的导弹全部打完。而这些导弹全部记为为同一组，再在没打下来的导弹中任选一个重复上述步骤，直到打完所有导弹。

// （2）假设我们得到了最小划分的K组导弹，从第a(1<=a<=K)组导弹中任取一个导弹，必定可以从a+1组中找到一个导弹的高度比这个导弹高（因为假如找不到，那么它就是比a+1组中任意一个导更高，在打第a组时应该会把a+1组所有导弹一起打下而不是另归为第a+1组），同样从a+1组到a+2组也是如此。那么就可以从前往后在每一组导弹中找一个更高的连起来，连成一条上升子序列，其长度即为K;

// （3）设最长上升子序列长度为P，则有K<=P;又因为最长上升子序列中任意两个不在同一组内(否则不满足单调不升)，则有

//     P>=K，所以K=P。

#include <iostream>
#include <algorithm>
using namespace std;
const int N = 100010;
int a[N], d1[N], d2[N], n;
int main() {
	while (scanf("%d", &a[++n])!=EOF); n--;		//输入
	int len1 = 1, len2 = 1;		//初始长度为1
	d1[1] = a[1];		//用于求不上升序列长度   序列不严格单调，故用upper_bound
	d2[1] = a[1];		//用于求上升序列长度    序列严格单调，用lower_bound，可以在找到相同元素时将其替换
	for (int i=2; i<=n; i++) {		
		if (d1[len1] >= a[i]) d1[++len1] = a[i];		
		else {		
			*upper_bound(d1 + 1, d1 + 1 + len1, a[i], greater<int>())=a[i];  //upper_bound 和 lower_bound 只差一个等号，即upper_bound求大于目标值的下标，lower_bound求大于等于目标值的下标
		}
		if (d2[len2] < a[i]) d2[++len2] = a[i];		
		else {
			*lower_bound(d2 + 1, d2 + 1 + len2, a[i])=a[i];
		}
	}
	cout << len1 << endl << len2;
    system("pause");
}