class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(sum>9*num){
            return "";
        }
        string res="";

        int nines=sum/9;
        res.append(nines,'9');

        int rem=sum%9;
        if(rem>0){
            res+=to_string(rem);
        }

        if(res.length()<num){
            res.append(num-res.length(),'0');
        }
        return res;
    }
};