#include<iostream>
#include<vector>
using namespace std;
void backtrack(int n)
{
    int i = 1;
    vector<int> v;
    while(i > 0){
        if(v.size() == n){
            for(int j=0;j<v.size();j++)
                cout<<v[j]<<" ";
            cout<<endl;
            i--;
        }
        if(i <= n){
            v.push_back(i);
            i++;
        }
            

    }
}
int main()
{

}