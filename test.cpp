#include <cstring>
#include <iostream>
// #include<bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(NULL) {}
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode *reverseList(ListNode *head)
{
    if (head->next == NULL)
    {
        cout << head->val << endl;
        return head;
    }
    ListNode *tail = reverseList(head->next);
    ListNode *tmp = head->next;
    tmp->next = head;
    head->next = NULL;
    cout << tmp->val << " " << head->val << endl;
    return tail;
}
int main()
{
    ListNode* head = new ListNode(1);
    ListNode* node1 = new ListNode(2);
    ListNode* node2 = new ListNode(3);
    head->next = node1;
    node1->next = node2;
    ListNode* res = reverseList(head);
    system("pause");
}