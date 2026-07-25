class Solution {
public:
    int maxProduct(int n) {
        int max1=0;
        int max2=0;
        while(n){
            int r=n%10;
            if(r>max1){
                max2=max1;
                max1=r;
            }else if(r>max2){
                max2=r;
            }
            n/=10;
        }
        return max1*max2;
    }
};