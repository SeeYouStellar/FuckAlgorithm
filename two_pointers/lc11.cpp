/**
 * ? 水的面积 = min(height[l], height[r])*(r-l) = 短板*(r-l)
 * * 两个循环可算出面积最大值，需要使用双指针优化
 * * 双指针的关键在于可以去除掉一些不必要的循环状态(l,r) 
 * ! 容器的左右两侧的收缩改变水的面积，收缩会带来短板的改变以及底的长度变化。
 * ! 1. 向内收缩短板->短板可能变大也可能变小或不变，所以面积有变大可能
 * ! 2. 向内收缩长板->短板不变或变小，所以面积只可能变小（因为底也变小了）
 * ? 所以每次只需要收缩短板，即可朝着正确的答案迈进
 * * 初始时l=0，r=height.size()-1，不断向内收缩短板。

 * * 假设状态 S(i,j) 下 h[i]<h[j] ，在向内移动短板至 S(i+1,j) ，则相当于消去了 S(i,j−1),S(i,j−2),...,S(i,i+1)
 */
class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size()-1;
        int res = 0;
        while(l<r) {
            int sum = min(height[l], height[r])*(r-l);
            if(sum>res) res = sum;
            if(height[l]>height[r]) r--;
            else l++;
        }
        return res;
    }
};
