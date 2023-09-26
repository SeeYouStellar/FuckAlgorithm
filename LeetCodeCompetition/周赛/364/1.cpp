class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int one = 0;
        int zero = 0;
        for(int i=0;i<s.size();i++){
            one += (s[i]=='1');
            zero += (s[i]=='0');
        }
        string res="";
        for(int i=0;i<one-1;i++){
            res+='1';
        }
        for(int i=0;i<zero;i++){
            res+='0';
        }
        res+='1';
        return res;
    }
};