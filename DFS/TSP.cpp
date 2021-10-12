#include<iostream>
#include<vector>
using namespace std;
int n;
int price[100][100];
class bNode{
public:
    int path[100];
    int choice;
    int cc;
    int lb;
    int lev;
};
void backtrack(bNode* & node, int index)
{
    if(index == n){
        
        return ;
    }   
    int flag = 0;
    for(int i=0;i<n;i++){
        int j;
        for(j=0;j<node->lev;j++){
            if(node->path[j] == i)
                flag == 1;
        if(flag)
            continue;
        
        node->path[node->lev] = i;
        node->lb += price[node->choice][i];
        node->choice = i;
        node->lev ++;
        backtrack(node, index+1);
        node->path[node->lev-1] = 0;
        node->lb -= price[node->choice][i];
        node->choice = node->path[node->lev-2];
        node->lev --;
        }
    }
}   
int main()
{
    bNode* node = new bNode();
    node->cc = 0;
    node->choice = -1;
    node->lb = 0;
    node->lev = 0;
    backtrack(node, 0);
}