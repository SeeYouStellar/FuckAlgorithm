#include<bits/stdc++.h>
using namespace std;
struct node{
    int weight;
    vector<int> child;
}Node[110];
int n, m, s;
vector<vector<int>> ans;
vector<int> tmp;
bool cmp(int a, int b){
    return Node[a].weight > Node[b].weight;
}
void dfs(int root, int sum)
{
    if(!Node[root].child.size() && sum==s){
        ans.push_back(tmp);
        return;
    }
    for(int i=0;i<Node[root].child.size();i++){
        if(sum+Node[Node[root].child[i]].weight<=s){
            tmp.push_back(Node[Node[root].child[i]].weight);
            dfs(Node[root].child[i], sum+Node[Node[root].child[i]].weight);
            tmp.pop_back();
        }
    }
}

int main()
{
    cin>>n>>m>>s;
    for(int i=0;i<n;i++)
        cin>>Node[i].weight;
    string a, b;
    int c;
    for(int i=0;i<m;i++){
        cin>>a>>c;
        for(int j=0;j<c;j++){
            cin>>b;
            Node[(a[0]-'0')*10+a[1]-'0'].child.push_back((b[0]-'0')*10+b[1]-'0');
        }
        
    }
    tmp.push_back(Node[0].weight);
    dfs(0, Node[0].weight);
    sort(ans.begin(), ans.end(), greater<vector<int>>());   // 这里与算法笔记的代码不同，算法笔记的代码是错误的
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j];
            if(j<ans[i].size()-1) cout<<" ";
        }
        cout<<endl;
    }
}