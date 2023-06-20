// 把三重循环简化成两重循环
vector<vector<int>> threeSum(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    int s = nums.size();
    for (int i = 0; i < s; i++)
    {
        int k = s - 1;
        if (i == 0 || nums[i - 1] != nums[i])
        {
            for (int j = i + 1; j < s; j++)
            {
                if (j == i + 1 || nums[j - 1] != nums[j])
                {
                    if (nums[i] + nums[j] + nums[k] < 0)
                        continue;
                    while (k > j && nums[i] + nums[j] + nums[k] > 0)
                    {
                        k--;
                    }
                    if (k == j) // 没有足够小的k使得三数相加为0，故后续若j增大，更不可能有足够小的k，所以直接跳出第二重循环
                        break;
                    if (nums[i] + nums[j] + nums[k] == 0)
                        ans.push_back({nums[i], nums[j], nums[k]});
                }
            }
        }
    }
    return ans;
}