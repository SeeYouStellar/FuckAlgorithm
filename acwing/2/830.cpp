#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
int n, a[N];

int main() {
    scanf("%d", &n);
    for(int i=0;i<n;i++) scanf("%d", &a[i]);
    stack<int> st;
    for(int i=0;i<n;i++) {
        while(!st.empty() && a[st.top()]>=a[i]) 
            st.pop();
        printf("%d ", !st.empty()?a[st.top()]:-1);
        st.push(i);
    }
    system("pause");
}