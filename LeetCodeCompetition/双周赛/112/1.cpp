class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        if((s1[0]-'a'+s1[2]-'a'==s2[0]-'a'+s2[2]-'a'&&(s1[0]==s2[0]||s1[0]==s2[2])) && (s1[1]-'a'+s1[3]-'a'==s2[1]-'a'+s2[3]-'a'&&(s1[1]==s2[1]||s1[1]==s2[3])))
            return true;
        return false;
    }
};