//push操作顺序为前序遍历，pop操作顺序为中序遍历，然后就是根据前序和中序建立二叉树
#include<bits/stdc++.h>
using namespace std;
int N;
int pre[30], in[30], post[30];
vector<int> v;
struct node{
    int data;
    node* lchild;
    node* rchild;
};
node* create(int inl, int inr, int prel, int prer)
{
    if(prel > prer) return NULL;
    node* root = new node();
    root->data = pre[prel];
    int i;
    for(i=inl;i<=inr;i++)
        if(in[i] == root->data) break;
    int numleft = i - inl;
    root->lchild = create(inl, i-1, prel+1, prel+numleft);
    root->rchild = create(i+1, inr, prel+numleft+1, prer);
    return root;
}
void BFS(node* root)
{
    queue<node*> q;
    q.push(root);
    int count = 0;
    while(!q.empty()){
        node* now = q.front();
        q.pop();
        count++;
        cout<<now->data;
        if(count < N) cout<<" ";                         
        if(now->lchild) BFS(now->lchild);
        if(now->rchild) BFS(now->rchild);
    }
}

void postorder(node* root)
{
    if(root == NULL)
        return ;
    postorder(root->lchild);
    postorder(root->rchild);
    v.push_back(root->data);
}
int main()
{
    cin>>N;
    int j = 0, k = 0;
    stack<int> sk;//题目给的是用桟模拟中序遍历和前序遍历
    for(int i=0;i<N*2;i++){
        string s;
        int a;
        cin>>s;
        if(s[1] == 'u') {cin>>a;pre[j++] = a;sk.push(pre[j-1]);}
        else {in[k++] = sk.top();sk.pop();}
    }
    node* root = create(0, N-1, 0, N-1);
    postorder(root);
    for(int i=0;i<N;i++){
        cout<<v[i];
        if(i < N-1) cout<<" ";
    }
    cout<<endl;
    system("pause");
}
/*
注意，题意是用桟模拟先序，中序遍历，不是用桟实现，区别在于前者的push x和pop x的x是按先序和中序顺序来的，而后者是按深度优先搜索来的
举个例子：题目中的push 1 push 2 push 3 后是pop pop ，而不是pop push 4，很明显后面这种输出方式是深度优先搜索的的入栈顺序。
所以题目中的这种输出方式不是深度优先搜索的输出方式。只是用push  的顺序代表前序，pop的顺序代表中序

中序，前序，后序遍历原理都是深度优先搜索，事实上，都是先访问父节点，再访问其左儿子、右儿子。
区别只是对父节点的处理放在什么位置，而不是访问的先后。
那么入栈的顺序就是先序遍历
出栈的顺序就是中序遍历
*/
