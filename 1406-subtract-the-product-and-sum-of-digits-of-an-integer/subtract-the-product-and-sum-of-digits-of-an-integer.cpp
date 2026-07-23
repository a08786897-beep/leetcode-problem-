class Solution {
public:
    int subtractProductAndSum(int n) {
        int multiply=1;
        int sum=0;
        while(n>0){
            int r =n%10;
            multiply *= r;
            sum += r;
            n/=10;
        }
        return multiply-sum;
    }
};