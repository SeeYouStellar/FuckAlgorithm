class Solution {
public:
    class Trie{
    private:
        int isend;
        Trie* next[26];
    public:
        Trie(){
            isend = 0;
            memset(next, NULL, sizeof(next));
        }
        void insert(string &word){
            Trie* p = this;
            for(char c:word){
                if(p->next[c-'a']==NULL){
                    Trie* node = new Trie();
                    p->next[c-'a'] = node;
                }
                p = p->next[c-'a'];
            }
            p->isend = 1;
        }
        string getPrefix(string &word){
            string res;
            Trie* p = this;
            for(char c:word){
                if(p->next[c-'a']==NULL && !p->isend){
                    // cout<<res<<endl;
                    return word;
                }
                else if(p->isend){
                    // cout<<res<<endl;
                    return res;
                }
                res+=c;
                p = p->next[c-'a'];
            }
            return word;
        }
    };
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie* obj = new Trie();
        for(string s:dictionary){
            obj->insert(s);
        }
        string tmp;
        vector<string> v;
        for(char c:sentence){
            if(c != ' '){
                tmp+=c;
            }else{
                v.push_back(obj->getPrefix(tmp));
                tmp.clear();
            }
        }
        v.push_back(obj->getPrefix(tmp));
        string res;
        for(int i=0;i<v.size();i++){
            res+=v[i];
            if(i<v.size()-1)res+=' ';
        }
        return res;
    }
};