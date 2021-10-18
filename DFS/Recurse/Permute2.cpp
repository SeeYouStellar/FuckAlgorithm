//按字典序排列
//全排列

#include <iostream>
using namespace std;
const int maxn = 10000;
int a[maxn];
bool flag[maxn] = { false };

void combine(int index, int n) {
	if (index == n) {
		for (int i = 0; i < n; i++)
			cout<<a[i]<<' ';
		cout<<endl;
		return;
	}
	for (int i = 0; i < n; i++) { //在多叉树的同一个节点处，其子节点按字典序（从小到大）赋值，比如1->2，1->3。
		if (flag[i] == false) {   //flag[i]=true or false 代表 数字（i+1）是否已经在该次序列中使用
			a[index] = i + 1;   	  //当i+1这个数可用时，则将其加入a数组
			flag[i] = true;       //
			combine(index + 1,n);
			flag[i] = false;
		}
	}
}

int main() {
	int n;
	while (scanf("%d", &n) != EOF)
		combine(0, n);
	return 0;
}
// #include<bits/stdc++.h>
// using namespace std;
// int a[10]={1,2,3,4,5,6,7,8,9,10};
// int main(){
//     int n;
//     scanf("%d",&n);
//     do{
//         for(int i = 0;i<n;i++){
//             if(i<n-1)
//             printf("%d ",a[i]);
//             else
//             printf("%d",a[i]);
//         }
// 		printf("\n");
//     }while(next_permutation(a,a+n));
//     system("pause");
//     return 0;
// }

