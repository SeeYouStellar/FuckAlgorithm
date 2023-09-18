class Solution {
public:
    void find(int x, int y, vector<vector<int>>& res, vector<int>& king, vector<int>& queenHash) {
        int kingx = king[0], kingy = king[1];
        kingx+=x;
        kingy+=y;
        while(kingx>=0 && kingx<8 && kingy>=0 && kingy<8){
            int key = kingx*8+kingy;
            if(queenHash[key]==1){
                res.push_back({kingx, kingy});   // 某个方向上找到第一个就返回
                break;
            }
            kingx+=x;
            kingy+=y;
        }
        return ;
    }
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        vector<int> queenHash(64, 0);
        for(auto queen:queens){
            queenHash[queen[0]*8+queen[1]]++;  // hash思想：64个格子，每组下标组成的哈希值都是唯一的，即从上到下从左到右数格子的个数
        }
        int X[8] = {0, -1, -1, -1, 0, 1, 1, 1};
        int Y[8] = {1, 1, 0, -1, -1, -1, 0, 1};
        vector<vector<int>> res;
        for(int i=0;i<8;i++){
            find(X[i], Y[i], res, king, queenHash);
        }
        return res;
    }
};