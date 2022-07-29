class Trie {
public:
    Trie() {
        isEnd = 0;
        memset(next, NULL, sizeof(next));
    }

    void insert(string word) {
        Trie* p = this;
        for(char c:word){
            if(p->next[c-'a']==NULL){
                Trie* node = new Trie();
                p->next[c-'a'] = node;
            }
            p = p->next[c-'a'];
        }
        p->isEnd = 1;
    }
    
    bool search(string word) {
        Trie* p = this;
        for(char c:word){
            if(p->next[c-'a']==NULL){
                return false;
            }
            p = p->next[c-'a'];
        }
        return p->isEnd;
    }
    
    bool startsWith(string prefix) {
        Trie* p = this;
        for(char c:prefix){
            if(p->next[c-'a']==NULL){
                return false;
            }
            p = p->next[c-'a'];
        }
        return true;
    }
private:
    Trie* next[26];
    int isEnd;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */