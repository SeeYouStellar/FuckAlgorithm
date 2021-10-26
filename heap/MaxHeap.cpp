/*
 * @Author: xinyu Li
 * @Date: 2021-10-26 12:23:04
 * @LastEditTime: 2021-10-26 16:56:49
 * @Description: 
 * @FilePath: \helloworld\fuck\heap\MaxHeap.cpp
 * I am because you are
 */
#include<iostream>
using namespace std;
int heap[1000] = {0, 85, 55, 82, 57, 68, 92, 99, 98, 66, 56}, N = 10;
void downadjust(int i) //O(logn) 和二叉树的搜索是同一个时间复杂度
{
    int j = i*2;
    while(i <= N){
        if(j + 1 <= N && heap[j + 1] > heap[j])
            j = j + 1;
        if(heap[i] < heap[j]){
            swap(heap[i], heap[j]);
            i = j;
            j = i*2;
        }else 
            break;
    }
}
void upadjust(int i)
{
    int now = i;
    while(now >= 1){
        if(heap[now] > heap[now/2]){
            swap(heap[now], heap[now/2]);
            now/=2;
        }else break;
    }
}
void createHeap() //O(n)
{
    for(int i=N/2;i>=1;i--)
        downadjust(i);
}
int Delete()  //O(logn)  大顶堆的删除只删根节点
{
    int out = heap[1];
    heap[1] = heap[N--];
    downadjust(1);
    return out;
}

void Insert(int x)
{
    int i = N;
    heap[++i] = x;
    upadjust(N);
}
void heapSort()  // O(nlogn)
{
    createHeap();
    int n = N;
    for(int i=0;i<n;i++){
        cout<<Delete(); 
        if(i < n - 1) cout<<" ";
    }
    cout<<endl;
}
int main()
{
    heapSort();
    system("pause");
}


