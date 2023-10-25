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
    // 快排，归并~O(nlogn)
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode* newhead = new ListNode(-1);
        ListNode* cur = newhead;
        while(l1!=NULL && l2!=NULL) {
            if(l1->val < l2->val) {
                cur->next = l1;
                l1 = l1->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        if(l1!=NULL) cur->next = l1;
        if(l2!=NULL) cur->next = l2;

        return newhead->next;
    }
    ListNode* findMid(ListNode* l, ListNode* r) {
        ListNode* fast = l, *slow = l;
        while(fast!=r) {
            fast = fast->next;
            slow = slow->next;
            if(fast!=r) fast = fast->next;
        }
        return slow;
    }
    ListNode* mergeSort(ListNode* l, ListNode* r) {
        if(l == NULL) return l;
        if(l->next == r) {
            l->next = NULL;
            return l;
        }
        ListNode* mid = findMid(l, r);
        return merge(mergeSort(l, mid), mergeSort(mid, r));
    }
    ListNode* sortList(ListNode* head) {
        return mergeSort(head, NULL);
    }
};