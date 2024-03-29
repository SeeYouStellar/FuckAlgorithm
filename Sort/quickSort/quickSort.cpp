#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;

int n, q[N];

void quick_sort(int l, int r)
{
    if (l == r) return;  // 不会出现l>r的情况，可以使用][2,1]这个例子来试一下，递归的边界永远是l==r的情况

    int i = l - 1, j = r + 1, x = q[l + r >> 1];  
    while (i < j)
    {
        do i ++ ; while (q[i] < x);
        do j -- ; while (q[j] > x);
        if (i < j) swap(q[i], q[j]);
    }
    quick_sort(l, j), quick_sort(j+1, r);
}

int main() {
    scanf("%d", &n);    
    for(int i=0;i<n;i++) scanf("%d", &q[i]);
    quick_sort(0, n-1);
    for(int i=0;i<n;i++) printf("%d ", q[i]);
}

// 为了防止死循环（用[2,1]例子可观测）当分治时使用(l,j),(j+1,r)这种拆分方式时，上边的x不能取q[r]；同理当按照(l, x-1),(x, r)拆分时，不能用q[l]
