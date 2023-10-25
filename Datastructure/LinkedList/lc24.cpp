/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode *p=head, *q=head->next, *pre;
        ListNode* newhead=new ListNode(-1, head);  // ? 哨兵节点，方便记录交换后的头节点
        pre = newhead;
        while(p!=NULL && q!=NULL) {
            
            pre->next = q;
            p->next = q->next;
            q->next = p;
            
            pre = p;
            p = p->next;
            if(p!=NULL)q = p->next;

        }
        return newhead->next;
    }
};