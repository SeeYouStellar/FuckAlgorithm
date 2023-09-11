// 输出拓扑排序即可
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int in_degree[2010] = {0};
        vector<vector<int>> out_degree(numCourses, {-1});
        for(auto i:prerequisites){
            in_degree[i[0]]++;
            out_degree[i[1]].push_back(i[0]);
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(in_degree[i]==0)
                q.push(i);
        }
        vector<int> studyPath;
        while(!q.empty()){
            int top = q.front();
            q.pop();
            studyPath.push_back(top);
            for(int i=1;i<out_degree[top].size();i++){
                in_degree[out_degree[top][i]]--;
                if(in_degree[out_degree[top][i]]==0)
                    q.push(out_degree[top][i]);
            }
        }
        if(studyPath.size()!=numCourses) return {};
        return studyPath;
    }
};