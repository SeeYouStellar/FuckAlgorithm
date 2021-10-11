#include<iostream>
#include<vector>
using namespace std;
int cc;
int bestc;
int path[100];
int n;
int getcc(int cc, int i)
{
    for()
}
void backtrack(int i)
{
    if(i == n){
        
    }
    for(int j=0;j<n;j++){
        swap(path[i], path[j]);
        cc = getcc(cc, i);
        if(bestc > cc){
            backtrack(i+1);
        }
        swap(path[i], path[j]);
    }
}
int main()
{
    backtrack(1);
}