class Solution {
public:
    vector<int> partitionLabels(string s) {
        if(s.size()==1) return vector{1};
        vector<int> end(30, -1);
        vector<int> res;
        for(int i=0;i<s.size();i++) end[s[i]-'a'] = i;
        int l = 0, r = end[s[0]-'a'], tmp = 0;
        while(l<=r && r<s.size()) {
            if(end[s[l]-'a']<=r) l++;
            else r = end[s[l++]-'a'];
            if(l>r) {
                res.push_back(r-tmp+1);
                if(l>=s.size()) break;
                tmp = l;
                r = end[s[l]-'a'];
            }
            // cout<<l<<" "<<r<<endl;
        }
        return res;
    }
};
/**
 * ! 题目要求：每个字母只出现在一个片段里，并且片段尽可能多
 * ? 双指针
 * 
 * * 1.先得到每个字母最后出现的下标
 * * 2.L指向每个片段的开头，R指向每个片段开头字母最后出现的下标
 * * 3.移动L，判断L下标处的字母最后出现的下标是否在R左侧，如果是在左侧则向右移动L，否则则将R指向该下标字母最后出现的位置
 * * 4.当L超过R时，说明R当前的片段里的字母都只在当前片段内，记录片段长度
 * 
 * ! 这种扫描的方式可以做到片段尽可能多
 */