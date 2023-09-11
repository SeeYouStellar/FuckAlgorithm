/*
 * @Author: xinyu Li
 * @Date: 2022-02-20 14:20:10
 * @LastEditTime: 2022-02-20 15:27:16
 * @Description: 
 * @FilePath: \helloworld\fuck\Sort\quickSort.cpp
 * I am because you are
 */
#include <bits/stdc++.h>
using namespace std;
int A[10] = {3, 2, 1, 5, 8, 4, 7, 4, 9, 5};
int part(int l, int r)
{
    int tmp = A[l];
    while(l < r){
        while(l < r && tmp <= A[r]) r--;
        A[l] = A[r];
        while(l < r && tmp >= A[l]) l++;
        A[r] = A[l];
    }
    A[l] = tmp;
    return l;
}
void quickSort(int l, int r)
{
    if(l > r) return;
    int p = part(l, r); 
    quickSort(l, p-1);
    quickSort(p+1, r);
}
int main()
{
    quickSort(0, 9);
    for(int i=0;i<10;i++){
        cout<<A[i]<<" "; 
    }
    system("pause");
}