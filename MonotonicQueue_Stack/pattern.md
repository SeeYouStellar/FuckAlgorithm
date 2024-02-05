# 单调队列和单调栈

区别：
1. 单调队列解决距离当前位置**最远**位置的符合条件的元素
2. 单调栈解决距离当前位置**最近**位置的符合条件的元素


# 单调队列

## 思路：
1. 判断需要维护队列的单调性
2. 判断遍历到的下标元素是否需要入队
3. 确定如何判断出队条件

## 模板-滑动窗口最大值/最小值
寻找每个下标处指定窗口大小内的元素最大值/最小值，
```c++
void getbig() {
    deque<int> dq;
    for(int i=0;i<n;i++) {
        while(!dq.empty() && i-dq.front()>=k) 
            dq.pop_front();
        while(!dq.empty() && a[dq.back()]<a[i]) 
            dq.pop_back();
        dq.push_back(i);
        if(i>=k-1) printf("%d ", a[dq.front()]);
    }
}

void getsmall() {
    deque<int> dq;
    for(int i=0;i<n;i++) {
        while(!dq.empty() && i-dq.front()>=k) 
            dq.pop_front();
        while(!dq.empty() && a[dq.back()]>a[i]) 
            dq.pop_back();
        dq.push_back(i);
        if(i>=k-1) printf("%d ", a[dq.front()]);
    }
}
```
# 单调栈

## 思路

## 模板-距离当前下标最近的比当前下标元素小的元素

```c++
void findsmall() {
    stack<int> st;
    for(int i=0;i<n;i++) {
        while(!st.empty() && a[st.top()]>=a[i]) // 严格小于的才行，等于同样不符合要求
            st.pop();
        printf("%d ", !st.empty()?a[st.top()]:-1);
        st.push(i);
    }
}
void findbig() {
    stack<int> st;
    for(int i=0;i<n;i++) {
        while(!st.empty() && a[st.top()]<=a[i]) 
            st.pop();
        printf("%d ", !st.empty()?a[st.top()]:-1);
        st.push(i);
    }
}
```