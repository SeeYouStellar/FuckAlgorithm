/*
 * @Author: xinyu Li
 * @Date: 2022-02-12 10:55:22
 * @LastEditTime: 2022-02-12 18:48:37
 * @Description:  二叉树的搜索、查找、创建、层序遍历
 * @FilePath: \helloworld\1.cpp
 * I am because you are
 */
#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* lchild;
    Node* rchild;
};

void bfs(Node* root) //层序遍历
{
    queue<Node*> q;
    q.push(root);       
    while(!q.empty()){
        Node* top = q.front();
        q.pop();
        if(top->lchild != NULL) q.push(top->lchild);
        if(top->rchild != NULL) q.push(top->rchild);
        
    }
}
void postOrder(Node* root)  //后序遍历
{
    if(root == NULL){
        return;
    }
    postOrder(root->lchild);
    postOrder(root->rchild);
    cout<<root->data;
}

Node* newNode(int data)
{
    Node* root;
    root->data = data;
    root->lchild = NULL;
    root->rchild = NULL;
    return root;
}

//函数的形参和实参不是同一个东西，形参是实参的复制品，两个东西值是相同的。
//但是如果想要函数内外同时改变一个东西的值，最好传递指针，类似这里传结构体的指针
//如果需要改变传递的指针，并且同时反映到外部，那就需要引用

void insert(Node*& root, int data)          //传递的必须是指针，因为函数运行时，形参都是重现产生副本，而不是实参本身，故如果是结构体本身，那么函数内对结构体的修改不会反映到实参上
{
    if(root == NULL){
        root = newNode(data);
        return;
    }
    if(root->data > data)
        insert(root->lchild, data);
    else
        insert(root->rchild, data);
}
void search(Node*& root, int data)
{
    if(root == NULL){
        cout<<"bad";
        return;
    }
    if(root->data == data){
        cout<<"good";
        return;
    }
    if(root->data > data)
        search(root->lchild, data);
    else
        search(root->rchild, data);
}
Node* create(int data[], int n)
{
    Node* root = NULL;     
    for(int i=0;i<n;i++){
        insert(root, data[i]);
    }   
    return root;
}
int main()
{
    
}
