// 拓扑排序模板题
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int visit[2010]={0};  // 节点入读表
        vector<vector<int>> out_degree(numCourses, {-1});  // 节点出度表
        for(auto preq : prerequisites){
            visit[preq[0]]++;
            out_degree[preq[1]].push_back(preq[0]);
        }
        queue<int> q; 
        for(int i=0;i<numCourses;i++){
            if(visit[i]==0) q.push(i);  // 入度为0的节点入队
        } 
        while(!q.empty()){
            int top = q.front();
            q.pop();
            for(int i=1;i<out_degree[top].size();i++){
                visit[out_degree[top][i]]--;
                if(visit[out_degree[top][i]]==0)q.push(out_degree[top][i]);
            }
        }
        for(int i=0;i<numCourses;i++){
            if(visit[i]!=0) return false;
        }
        return true;
    }
};