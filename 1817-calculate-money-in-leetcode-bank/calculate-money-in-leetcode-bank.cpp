class Solution {
public:
    int totalMoney(int n) {
        int total_sum=0;
        int week=0;
        int day=1;

        for(int i=1;i<=n;i++){
            total_sum+=(week+day);
            day++;

            if(day>7){
                day=1;
                week++;
            }
        }
        return total_sum;
    }
};