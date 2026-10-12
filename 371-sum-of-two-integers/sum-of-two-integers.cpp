class Solution {
public:
    int getSum(int a, int b) {
        while(b!=0){
            int Sumwithout=a^b;

            int carry=(unsigned int)(a&b)<<1;

            a=Sumwithout;
            b=carry;
        }
        return a;
    }
};