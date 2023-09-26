class Solution {
public:
    int trap_dp(vector<int>& height)
    {
        int res = 0;
        vector<int> leftmax(height.size(), 0);  // leftmax[i]代表包含height[i]在内的左边所有元素最大值
        vector<int> rightmax(height.size(), 0);  // rightmax[i]代表包含height[i]在内的右边所有元素最大值
        leftmax[0] = height[0];
        rightmax[height.size()-1] = height[height.size()-1];
        for(int i=1;i<height.size();i++){
            leftmax[i] = max(height[i], leftmax[i-1]);
            rightmax[height.size()-i-1] = max(rightmax[height.size()-i], height[height.size()-i-1]);
        }
        for(int i=0;i<height.size();i++){
            res += min(leftmax[i], rightmax[i])-height[i];  // 只计算每个下标处自己的墙上面有多少雨
        }
        return res;
    }
    int trap_stack(vector<int>& height) {
        int ans = 0;
        stack<int> st;
        for (int i = 0; i < height.size(); i++)
        {
            while (!st.empty() && height[st.top()] < height[i])
            {
                int j = st.top();
                st.pop();
                if (st.empty()) break;
                int l = st.top();
                int r = i;
                int h = min(height[r], height[l]) - height[j];
                ans += (r - l - 1) * h;
            }
            st.push(i);
        }
        return ans;
    }
};

/*
个人不是很喜欢单调栈的解法，觉得dp的解法更加优雅易懂。
*/ 