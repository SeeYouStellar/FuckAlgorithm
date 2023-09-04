class Solution {
public:
    int minimumOperations(string num) {
        // 00 25 50 75
        int index5 = -1, index0 = -1;
        int maxindex = -1;
        for(int i=num.size()-1;i>=0;i--){
            if(num[i]=='7' && index5!=-1){
                maxindex = i;
                break;
            }else if(num[i]=='2' && index5!=-1){
                maxindex = i;
                break;
            }else if(num[i]=='5' && index0!=-1){
                maxindex = i;
                break;
            }else if(num[i]=='5' && index0==-1){
                index5 = i;
            }else if(num[i]=='0' && index0!=-1){
                maxindex = i;
                break;
            }else if(num[i]=='0' && index0==-1){
                index0 = i;
            }
        }
        if(maxindex == -1 && index0==-1){
            return num.size();
        }else if(maxindex == -1 && index0!=-1){
            return num.size()-1;
        }else{
            return num.size()-maxindex-2;
        }
    }
};