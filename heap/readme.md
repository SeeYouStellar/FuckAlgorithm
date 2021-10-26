<!--
 * @Author: xinyu Li
 * @Date: 2021-10-26 19:25:29
 * @LastEditTime: 2021-10-26 19:44:33
 * @Description: 
 * @FilePath: \helloworld\fuck\heap\readme.md
 * I am because you are
-->
#### 与本题无关，但是在查阅资料时发现，STL的sort算法，数据量大时采用QuickSort快排算法，分段归并排序。一旦分段后的数据量小于某个门槛，为避免QuickSort快排的递归调用带来过大的额外负荷，就改用Insertion Sort插入排序。如果递归层次过深，还会改用HeapSort堆排序。
##### ------参考侯捷的《stl源码剖析》

#### A1098的坑点：即给定的部分排序后的序列一定是已经经过排序过程的，不可能是未排过序的，所以只要输入的两个序列相同，一定是插入排序，判断第二个序列是否是排序过程中的序列的代码放在排序执行循环体的最后就可以符合题意
![avatar](坑点.png)