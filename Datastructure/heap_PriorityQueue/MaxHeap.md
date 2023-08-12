#### 大顶堆max heap的特性

1. 大顶堆是一种二叉堆，通过一棵完全二叉树实现
2. 保证每个根节点都比其子节点大，子节点之间的大小关系不定。故堆顶元素为二叉堆中的最大元素
3. 可以在O(1)时间内获取堆顶元素，可以在O(logn)时间内删除堆顶元素并调整大顶堆，可以在O(logn)时间内向堆中加入一个元素并调整大顶堆
4. 大顶堆下标为i(**i从1开始**)，其子节点下标分别为$i*2,i*2+1$
5. 拥有最大下标根节点的子树，其根节点的最大下标一定等于N/2，N为堆中元素个数
6. 某个节点下标i乘2大于N，那么它一定是叶子节点
   
**c++模板**：
```c++
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
    for(int i=N/2;i>=1;i--)  // 从第一个非叶子结点开始向下调整，遍历每个非叶子结点
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
```

**golang模板(从0实现)**：
```go
type MaxHeap struct {
    nums []float64
    n int
}
func (mh *MaxHeap)createMaxHeap(nums []float64) {
    mh.nums = append(mh.nums, -1) // 保证堆顶下标为1
    mh.nums = append(mh.nums, nums...)
    mh.n = len(nums)
    for i:=mh.n/2;i>=1;i-- {
        mh.Down(i)
    }
}
func (mh *MaxHeap)Push(num float64) {
    mh.nums = append(mh.nums, num)
    mh.n++
    mh.Up(mh.n)
}
func (mh *MaxHeap)Pop() (bool) {
    ok := false
    if !mh.Empty() {
        mh.nums[1] = mh.nums[mh.n]
        mh.nums = mh.nums[:mh.n]
        mh.n--
        mh.Down(1)
        ok = true   
    }
    return ok
}
func (mh *MaxHeap)Top() (float64, bool) {
    ok := false
    top := 0.0
    if !mh.Empty() {
        ok = true
        top = mh.nums[1]
    }
    return top, ok
}
func (mh *MaxHeap)Empty() bool{
    if mh.n==0 {
        return true
    } else {
        return false
    }
}
func (mh *MaxHeap)Down(i int) {
    root := i
    son := i*2
    for son <= mh.n {
        if son+1 <= mh.n && mh.nums[son] < mh.nums[son+1] {
            son = son+1
        }
        if mh.nums[son] > mh.nums[root] {
            mh.nums[son], mh.nums[root] = mh.nums[root], mh.nums[son]
            root = son
            son = root*2
        } else {
            break // 调整完毕
        }
    }
}
func (mh *MaxHeap)Up(i int) {
    root := i/2
    son := i
    for root >= 1 {
        if mh.nums[root] < mh.nums[son] {
            mh.nums[son], mh.nums[root] = mh.nums[root], mh.nums[son]
            son = root
            root = root/2
        } else {
            break
        }
    }
}
func main(nums []int) {
    pq := MaxHeap{}
    pq.createMaxHeap(nums)
    top,_:= pq.Top()
    pq.Pop()
    pq.Push(10)
}
```

**golang模板(container/heap接口实现)**
```go
type PriorityQueue []int

func (pq PriorityQueue) Len() int {
    return len(pq)
}

func (pq PriorityQueue) Less(i, j int) bool {
    return pq[i] > pq[j]
}

func (pq PriorityQueue) Swap(i, j int) {
    pq[i], pq[j] = pq[j], pq[i]
}

func (pq *PriorityQueue) Push(x interface{}) {
    *pq = append(*pq, x.(int))  // x.()是断言(assert)写法，因为x是interface{}类型,必须这么写
}


func (pq *PriorityQueue) Pop() interface{} {
    old, n := *pq, len(*pq)
    x := old[n - 1]
    *pq = old[0 : n-1]
    return x
}

func main() {
    pq := &PriorityQueue{}
    // 使用Push的方式初始化
    for i:=0;i<10;i++ {
        heap.Push(pq, i)
    }
    for i:=0;i<5;i++ {
        heap.Pop(pq).(int)
    }
    for len(*pq)!=0 {
        heap.Pop(pq).(int)
    }
    // 使用heap.Init初始化
    pq := &PriorityQueue{1, 2, 3}
    heap.Init(pq)
}
```

**golang模板(container/heap接口实现),自定优先级**
```go
package main

import (
	"container/heap"
	"fmt"
)

type Item struct {
	value    string // 优先级队列中的数据，可以是任意类型，这里使用string
	priority int    // 优先级队列中节点的优先级
	index    int    // index是该节点在堆中的位置
}

// 优先级队列需要实现heap的interface
type PriorityQueue []*Item

// 绑定Len方法
func (pq PriorityQueue) Len() int {
	return len(pq)
}

// 绑定Less方法，这里用的是小于号，生成的是小根堆
func (pq PriorityQueue) Less(i, j int) bool {
	return pq[i].priority < pq[j].priority
}

// 绑定swap方法
func (pq PriorityQueue) Swap(i, j int) {
	pq[i], pq[j] = pq[j], pq[i]
	pq[i].index, pq[j].index = i, j
}

// 绑定put方法，将index置为-1是为了标识该数据已经出了优先级队列了
func (pq *PriorityQueue) Pop() interface{} {
	old := *pq
	n := len(old)
	item := old[n-1]
	*pq = old[0 : n-1]
	item.index = -1
	return item
}

// 绑定push方法
func (pq *PriorityQueue) Push(x interface{}) {
	n := len(*pq)
	item := x.(*Item)
	item.index = n
	*pq = append(*pq, item)
}

// 更新修改了优先级和值的item在优先级队列中的位置
func (pq *PriorityQueue) update(item *Item, value string, priority int) {
	item.value = value
	item.priority = priority
	heap.Fix(pq, item.index)
}

func main() {
	// 创建节点并设计他们的优先级
	items := map[string]int{"二毛": 5, "张三": 3, "狗蛋": 9}
	i := 0
	pq := make(PriorityQueue, len(items)) // 创建优先级队列，并初始化
	for k, v := range items {             // 将节点放到优先级队列中
		pq[i] = &Item{
			value:    k,
			priority: v,
			index:    i}
		i++
	}
	heap.Init(&pq) // 初始化堆
	item := &Item{ // 创建一个item
		value:    "李四",
		priority: 1,
	}
	heap.Push(&pq, item)           // 入优先级队列
	pq.update(item, item.value, 6) // 更新item的优先级
	for len(pq) > 0 {
		item := heap.Pop(&pq).(*Item)
		fmt.Printf("%.2d:%s index:%.2d\n", item.priority, item.value, item.index)
	}
}

```