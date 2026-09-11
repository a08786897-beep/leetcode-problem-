class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        vector<int> count(10,0);

        for(int d: digits){
            count[d]++;
        }

        int vaild_count=0;

        for(int i = 100;i<=998;i+=2){
            int d1=i/100;
            int d2=(i/10)%10;
            int d3=i%10;

            vector<int> required(10,0);
            required[d1]++;
            required[d2]++;
            required[d3]++;


            if(count[d1]>=required[d1] && count[d2]>=required[d2] && count[d3]>=required[d3]){
                vaild_count++;
            }
        }
        return vaild_count;
    }
};