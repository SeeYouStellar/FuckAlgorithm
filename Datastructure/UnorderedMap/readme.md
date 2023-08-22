### 剑指35 复杂链表的复制

> 与普通链表不同点：复杂链表有两个指针成员，一个随机指向$random$，一个$next$。如果顺序复制的话，有可能该指向的节点还未创建。

```c++
class Solution {
public:
    unordered_map<Node*, Node*> cachedNode;

    Node* copyRandomList(Node* head) {
        if (head == nullptr) {
            return nullptr;
        }
        if (!cachedNode.count(head)) {
            Node* headNew = new Node(head->val);
            cachedNode[head] = headNew;
            headNew->next = copyRandomList(head->next);
            headNew->random = copyRandomList(head->random);
        }
        return cachedNode[head];
    }
};
```

**思路：** 递归创建，判断当前节点是否已经创建，如果未创建就创建，并且两个指向分别调用递归创建。