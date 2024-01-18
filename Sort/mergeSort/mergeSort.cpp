/*
 * @Author: xinyu Li
 * @Date: 2022-02-20 13:44:39
 * @LastEditTime: 2022-02-20 14:19:05
 * @Description: 
 * @FilePath: \helloworld\fuck\Sort\mergeSort.cpp
 * I am because you are
 */
#include <bits/stdc++.h>
using namespace std;
int A[1000] = {3, 2, 8, 5, 6, 9, 2, 1, 0};
void merge(int l1, int r1, int l2, int r2)
{
    int i = l1, j = l2, tmp[1000] = {0}, index = 0;
    while(i <= r1 && j <= r2){
        if(A[i] <= A[j]) tmp[index++] = A[i++];
        else tmp[index++] = A[j++]; 
    }
    while(i <= r1) tmp[index++] = A[i++];
    while(j <= r2) tmp[index++] = A[j++];
    for(int k=0;k<index;k++)
        A[l1+k] = tmp[k];
}
void mergeSort(int l, int r)
{
    // l == r :只有一个元素时不需要分，直接返回
    if(l < r){
        int mid = (l + r)/2;
        mergeSort(l, mid);
        mergeSort(mid+1, r);
        merge(l, mid, mid+1, r);
    }
}
int main()
{
    mergeSort(0, 8);
    for(int i=0;i<9;i++){
        cout<<A[i]<<" "; 
    }
    system("pause");
}
