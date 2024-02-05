#include<bits/stdc++.h>
using namespace std;

const int N = 1e6+10;
int n, k, a[N];

void getbig() {
    deque<int> dq;
    for(int i=0;i<n;i++) {
        while(!dq.empty() && i-dq.front()>=k) 
            dq.pop_front();
        while(!dq.empty() && a[dq.back()]<a[i]) 
            dq.pop_back();
        dq.push_back(i);
        if(i>=k-1) printf("%d ", a[dq.front()]);
    }
}

void getsmall() {
    deque<int> dq;
    for(int i=0;i<n;i++) {
        while(!dq.empty() && i-dq.front()>=k) 
            dq.pop_front();
        while(!dq.empty() && a[dq.back()]>a[i]) 
            dq.pop_back();
        dq.push_back(i);
        if(i>=k-1) printf("%d ", a[dq.front()]);
    }
}

int main() {
    scanf("%d%d", &n, &k);
    for(int i=0;i<n;i++) scanf("%d", &a[i]);
    getsmall();
    cout<<endl;
    getbig();
    return 0;
}