class Solution {
public:
    bool judgeSquareSum(int c) {
        if(c==1){
            return true;
        }
        long long i=0,j=sqrt(c);
        while(i<=j){
            if(((i*i)+(j*j))==c){
                return true;
            }if(((i*i)+(j*j))<c){
                i++;
            }if(((i*i)+(j*j))>c){
                j--;
            }
        }
        return false;
    }
};