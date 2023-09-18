class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<int> in_degree(numCourses, 0);
        vector<vector<int>> out_degree(numCourses, {-1});
        vector<vector<bool>> ispre(numCourses, vector<bool>(numCourses, false)); // ispre[i][j]：i是否是j的先修课程
        for(auto& x:prerequisites){
            in_degree[x[1]]++;
            out_degree[x[0]].push_back(x[1]);
        }
        queue<int> q;
        vector<int> outq;  // 存储已经出队的节点
        for(int i=0;i<numCourses;i++){
            if(!in_degree[i])
                q.push(i);
        }
        while(!q.empty()){
            int top = q.front();
            q.pop();
            for(int i=1;i<out_degree[top].size();i++){
                ispre[top][out_degree[top][i]] = true;
                for(int j=0;j<outq.size();j++){  // 间接先修节点范围：直接先修节点的先修课程。top此时是out_degree[top][i]的直接先修节点，top的先修节点一定是已经出对的节点
                    if(ispre[outq[j]][top]) ispre[outq[j]][out_degree[top][i]] = true;
                }
                in_degree[out_degree[top][i]]--;
                if(!in_degree[out_degree[top][i]]) q.push(out_degree[top][i]);
            }
            outq.push_back(top);
        }
        vector<bool> res;
        for(auto& x:queries){
            res.push_back(ispre[x[0]][x[1]]);
        }
        return res;
    }
};

/*

利用一个n*n的二维表ispre[i][j]，记录某个节点是否是某个节点的先修节点

直接先修节点可以通过out_degree数组找到

间接先修节点是直接先修节点的（间接+直接）先修节点

当某个节点出队时，可以确定：
1. 遍历out_degree[top]数组，is[pre][out_degree[top][i]] = true
2. 遍历top的先修节点，is[top的先修节点][out_degree[top][i]] = true

其中top的先修节点的先修节点只可能从已经出队的outq数组中寻找。

*/