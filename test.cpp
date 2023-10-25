#include<bits/stdc++.h>
using namespace std;
int a[10] = {2, 1, 5, 3, 4};
int partition(int l, int r) {
    int target = a[l]; // 选择任意下标位置元素
    while(l<r) {
        while(l<r && target<=a[r]) r--;
        a[l] = a[r];
        while(l<r && target>=a[l]) l++;
        a[r] = a[l];
    }
    a[l] = target;
    return l;
}
void quickSort(int l, int r) {
    if(l>=r) return ;
    int qivot = partition(l, r);
    quickSort(l, qivot-1);
    quickSort(qivot+1, r);
}

int main() {
    quickSort(0, 4);
    for(int i=0;i<5;i++) cout<<a[i]<<" ";
    system("pause");
}