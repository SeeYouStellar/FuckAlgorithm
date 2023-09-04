class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int res = 0;
        for(int i=low;i<=high;i++){
            string num = to_string(i);
            if(num.size()%2!=0){
                continue;
            }
            int sum1 = 0;
            for(int j=0;j<num.size()/2;j++){
                sum1+=num[j]-'0';
            }
            int sum2 = 0;
            for(int j=num.size()/2;j<num.size();j++){
                sum2+=num[j]-'0';
            }
            if(sum1==sum2) 
                res++;
        }   
        return res;
    }
};