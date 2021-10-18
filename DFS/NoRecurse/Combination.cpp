#include <bits/stdc++.h>
using namespace std;
int n;
int r;
void backtrack()
{
    int i, a = 0, pop = false, top;
    stack<int> buf;
    vector<int> out;
    buf.push(1);
    out.push_back(1);
    while(buf.size()){
        if(a == r){
            for(int j=0;j<r;j++){
                cout<<out[j]<<" ";
            cout<<endl;
            }
            pop = true;
        }
        top = buf.top()+1;
        if(top == n+1){
            buf.pop();
            out.pop_back();
            pop = true;
            continue;
        }
        if(pop){
            buf.pop();
            out.pop_back();
            pop = false;
        }
        if(a <= r){
            buf.push(top);
            out.push_back(top);

        }
    }
}
int main()
{
    cin>>n>>r;
    backtrack();
    system("pause");
}