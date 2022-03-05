<!--
 * @Author: xinyu Li
 * @Date: 2022-02-05 19:37:34
 * @LastEditTime: 2022-02-10 18:43:37
 * @Description: 
 * @FilePath: \helloworld\fuck\DFS\Recurse\README.md
 * I am because you are
-->
>DFS：求解最值问题

## DFS有两种搜索模型：
1. 排列树
2. 子集树

## DFS有三个条件：
1. 边界条件：决定递归结束的条件，这个条件必须是等式条件，否则递归无法停止（**关键**）
2. 最值条件：DFS求解最值问题的标志是题干中的最值条件。在获得一个可行解后，需要判断这个条件，才能得出最优解
3. 剪枝条件：不是前两种条件的条件即为剪枝条件。有些搜索路径不需要到达边界条件就可以排除，那么需要用剪枝条件。

以上三个条件的选取可以大概可以分成三种情况。**第一种**是题目只给定了树的深度这一种约束，自然树的深度成为边界条件，并且无剪枝条件。**第二种**是题目中给定的另外的约束条件是不等式形式的，这种情况下深度约束仍然是边界条件，而另外的约束可成为剪枝条件。类似01背包问题，给定物品数量，给定背包重量，要求物体总重不超过背包重量。**第三种**是题目给定的约束条件中有等式条件，就比如*A1103*这道题中，底数数量的约束和底数平方和约束都是必须要达到某某值，否则不是一个可行解，所以这两个约束可以当作边界条件，那么自然深度条件变为了约束条件。

## DFS代码模型：
1. 子集树模型
```
void DFS(递归深度n, ...){
    if( 边界条件 )
    {
        if(最值条件)
        {
            ...
        }
    }
    ...
    DFS(n+1, 不选择)
    if(剪枝条件){
        ...
        DFS(n+1, 选择)
    } 
}

```
>**Ex:01bag**
```
void DFS(int sumw, int sumv, int index)
{
    if(index == n){                       // 边界条件
        if(maxv < sumv){                  // 最值条件
            maxv = sumv;
            memcpy(arr, a, 5*sizeof(int));
        } 
        return ;
    }
    if(sumw + w[index] <= T){             // 剪枝条件
        a[index] = 1;
        DFS(sumw+w[index], sumv+v[index], index+1);
    }
    a[index] = 0;
    DFS(sumw, sumv, index+1);
}
```
>**tip**：上面的模型中使用的剪枝条件是包含每个节点的左子节点的信息，这样到达叶节点的父节点时，也可以判断叶节点是否满足该剪枝条件，那么在判断边界条件的if语句内就不需要额外判断该剪枝条件了。如果代码如下，就会漏掉叶节点的剪枝判断。
```
void DFS(int sumw, int sumv, int index)
{
    if(index == n){                       // 边界条件
        if(maxv < sumv){                  // 最值条件
            maxv = sumv;
            memcpy(arr, a, 5*sizeof(int));
        } 
        return ;
    }
    if(sumw <= T) return;                 // 剪枝条件
    a[index] = 1;
    DFS(sumw+w[index], sumv+v[index], index+1);
    a[index] = 0;
    DFS(sumw, sumv, index+1);
}
```
>此时需要额外添加判断：
```
void DFS(int sumw, int sumv, int index)
{
    if(index == n){                       // 边界条件
        if(sumw <= T && maxv < sumv){     // 最值条件，此处添加了剪枝条件
            maxv = sumv;
            memcpy(arr, a, 5*sizeof(int));
        } 
        return ;
    }
    if(sumw <= T) return;                 // 剪枝条件
    a[index] = 1;
    DFS(sumw+w[index], sumv+v[index], index+1);
    a[index] = 0;
    DFS(sumw, sumv, index+1);
}
```

2. 排列树模型
