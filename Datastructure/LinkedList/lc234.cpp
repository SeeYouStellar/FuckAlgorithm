/*

? 判断回文链表
* 找到前半部分链表的尾节点。
* 反转后半部分链表。
* 判断是否回文。
* 返回结果。

*/
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return true;
        }
        ListNode* mid = getMid(head);
        mid->next = revert(mid->next);
        mid = mid->next;
        while(mid != NULL) {
            if(head->val != mid->val) {
                return false;
            }
            head = head->next;
            mid = mid->next;
        }
        return true;
    }
    ListNode* revert(ListNode* head) {  // ? 反转链表的指针三元组：last,now,Next
        ListNode* tmp = NULL, *Next = head->next, *last = NULL;
        while(Next != NULL) {
            head->next = last;
            tmp = Next->next;
            Next->next = head;

            // ! 注重先后顺序
            last = head;
            head = Next;
            Next = tmp;
        }
        return head;
    }
    ListNode* getMid(ListNode* head) {  // ? 快慢指针找到中间节点（如果是奇数则找到中间节点，如果是偶数则找到中间两个节点的第一个节点）
        ListNode *fast = head, *slow = head;
        while(fast->next!=NULL && fast->next->next!=NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
};
