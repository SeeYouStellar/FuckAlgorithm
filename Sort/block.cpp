#include<bits/stdc++.h>
using namespace std;
// 分块查找法：查找序列中第k小（大）的数
int main()
{
    
    int n, k;
    cin>>n>>k;
    vector<int> a(0, n);
    vector<int> block(0, sqrt(n));
    vector<int> table(0, n);
    for(int i=0;i<n;i++){
        cin>>a[i];
        table[a[i]]++;
        block[a[i]/sqrt(n)]++;
    }
    int sum = 0;
    int i = 0;
    while(sum+block[i]<k){
        i++;
    }
    int dis = sum - k;
    int i=1;
    int cnt = 0;
    while(table[sum+i]+cnt<dis){
        i++;
    } 
    
}