class Solution {
public:
    
    bool checkStrings(string s1, string s2) {
        int hash[30] = {0};
        for(int i=0;i<s1.size();i+=2){
            hash[s1[i]-'a']++;
        }
        for(int i=0;i<s2.size();i+=2){
            if(hash[s2[i]-'a']==0){
                return false;
            }
            hash[s2[i]-'a']--;
        }
        memset(hash, 0, sizeof(hash));
        for(int i=1;i<s1.size();i+=2){
            hash[s1[i]-'a']++;
        }
        for(int i=1;i<s2.size();i+=2){
            if(hash[s2[i]-'a']==0){
                return false;
            }
            hash[s2[i]-'a']--;
        }
        return true;
    }
};