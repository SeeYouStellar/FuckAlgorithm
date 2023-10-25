/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
// ! 双哈希map+非递归
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL) return NULL;
        Node* newhead=new Node(head->val), *now = head->next;
        Node* cur = newhead;
        unordered_map<Node*, Node*> map; // new list -> old list
        unordered_map<Node*, Node*> map_; // old list -> new list
        map[cur] = head;
        map_[head] = cur;
        while(now!=NULL) {
            cur->next = new Node(now->val);
            cur = cur->next;
            map[cur] = now;
            map_[now] = cur;
            now = now->next;
        }
        cur->next = NULL;
        cur = newhead;
        while(cur!=NULL) {
            cur->random = map_[map[cur]->random];
            cur = cur->next;
        }
        return newhead;
    }
};

// ! 递归

class Solution {
public:
    map<Node*, Node*> hash;
    Node* copyRandomList(Node* head) {
        if(!head) return NULL;
        if(!hash[head]){
            Node* newnode = new Node(head->val);
            hash[head]= newnode;
            newnode->next = copyRandomList(head->next);
            newnode->random = copyRandomList(head->random);
        }
        return hash[head];
    }
};