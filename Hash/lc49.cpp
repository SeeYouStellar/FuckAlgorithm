class Solution {
public:
    string getSum(string s) {
        string key = "";
        sort(s.begin(),s.end());
        int hash[28] = {0};
        for(auto& c:s){
            hash[c-'a']++;
        }
        for(int i=0;i<28;i++){
            if(hash[i]>0) {
                key+=('a'+i);
                key+=hash[i]+'0';
            }
        }
        return key;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, int> map;
        vector<vector<string>> res;
        for(auto& s:strs){
            if(map.count(getSum(s))!=0){
                int j = map[getSum(s)];
                res[j].push_back(s);
            }else{
                map[getSum(s)] = res.size();
                res.push_back(vector{s});
            }
        }
        return res;
    }
};


// 如何构造哈希的键是关键，来统一多个字符串