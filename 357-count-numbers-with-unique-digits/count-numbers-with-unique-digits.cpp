class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n==0) return 1;
        int totalCount=10;
        int current=9;
        int avilable=9;

        for(int i=2;i<=n && avilable>0;i++){
            current*=avilable;
            totalCount+=current;
            avilable--;
        }
        return totalCount;
    }
};