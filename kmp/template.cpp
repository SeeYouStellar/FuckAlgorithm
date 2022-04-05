#include <bits/stdc++.h>
using namespace std;
char pattern[500] = "ABABAB", text[500] = "ABABABABABABA";
int n, m, prefix[500];  //到达i下标（包括i）最大的公共前后缀
void getprefix()
{
    int i = 1, j = 0;
    prefix[0] = 0;
    while(i < n){
        if(pattern[i] == pattern[j])
            prefix[i++] = ++j;
        else{
            if(j==0)
                prefix[i++] = 0;//如果!j且pattern[i] != pattern[j]说明到i-1没有公共前后缀
            else                //在这种情况下prefix[i+1]的比较也绝对是pattern[i+1] != pattern[0]，即不可能与前面的元素结合形成大于1的公共前后缀。所以这里不用调整j
                j = prefix[j-1];
        }
    }
    for(int i=n-1;i>=1;i--) prefix[i] = prefix[i-1]; 
    prefix[0] = -1;   //由prefix数组构成next数组 
}
void KMP()
{
    //text[i]
    //pattern[j]
    int i = 0, j = 0;
    while(i < m){
        if(j == n){
            cout<<"find pattern at "<<i-j<<endl;
            j = prefix[j-1]+1;
        }
        if(j == -1) {i++;j++;}
        else if(text[i] == pattern[j]) {i++;j++;}
        else {j = prefix[j];}
    }
}
int main()
{
    n = strlen(pattern);
    m = strlen(text);

    getprefix();
    cout<<"prefix:";
    for(int i=0;i<n;i++) cout<<prefix[i]<<" ";
    cout<<endl;

    KMP();
    system("pause");
}