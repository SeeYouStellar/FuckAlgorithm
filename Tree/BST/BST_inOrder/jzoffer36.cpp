#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    Node *pre = NULL, *head = NULL;
    void inorder(Node *cur)
    {
        if (!cur)
            return;
        inorder(cur->left);
        if (pre)
        {
            cur->left = pre;
            pre->right = cur;
        }
        else
        {
            head = cur;
        }
        pre = cur;
        inorder(cur->right);
    }
    Node *treeToDoublyList(Node *root)
    {
        if (!root)
            return NULL;
        inorder(root);
        head->left = pre;
        pre->right = head;
        return head;
    }
};