/*
 * @Author: xinyu Li
 * @Date: 2022-02-20 15:54:51
 * @LastEditTime: 2022-02-20 16:00:09
 * @Description: 素数筛
 * @FilePath: \helloworld\fuck\basic\sushushai.cpp
 * I am because you are
 */
#include <bits/stdc++.h>
using namespace std;
int prime[100], primenumber = 0;
bool isornot[100];
void isprime()
{
    for(int i=2;i<100;i++){
        if(isornot[i]){
            prime[primenumber++] = i;
            for(int j=i+i;j<100;j+=i){
                isornot[j] = false;
            }
        }
    }
}
int main()
{
    memset(isornot, 1, sizeof(isornot));
    isornot[0] = 0;
    isornot[1] = 0;
    isprime();
    for(int i=0;i<100;i++){
        if(isornot[i]) cout<<i<<" ";
    }
    system("pause");
}