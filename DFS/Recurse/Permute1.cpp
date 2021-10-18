#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//全排列
//不按字典序——交换法
void FullPermute1(int n, int begin, vector<int>& arr)
{
    if(begin == n){
        for(int i=0;i<n;i++)
            cout<<arr[i]<<' ';
        cout<<endl;
        return;
    }
    for(int i=begin;i<n;i++){
        swap(arr[i], arr[begin]);
        FullPermute1(n, begin+1, arr);
        swap(arr[i], arr[begin]);  //使用这一句将会不按字典序
    }
}
int main()
{
    int n;
    vector<int> arr;
    cin>>n;
    for(int i=1;i<=n;i++)
        arr.push_back(i);
    FullPermute1(n, 0, arr);
    system("pause");
}