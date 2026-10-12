class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        long long MOD=1e9+7;
        vector<int> bitCount(30,0);

        for(int num:nums){
            for(int i=0;i<30;i++){
                if((num>>i)&1){
                    bitCount[i]++;
                }
            }
        }

        long long totalSum=0;

        for(int i=0;i<k;i++){
            long long currentNum=0;
            for(int j=0;j<30;j++){
                if(bitCount[j]>0){
                    currentNum |=(1LL <<j);
                    bitCount[j]--;
                }
            }
            totalSum=(totalSum+(currentNum*currentNum)%MOD)%MOD;
        }
        return totalSum;
    }
};