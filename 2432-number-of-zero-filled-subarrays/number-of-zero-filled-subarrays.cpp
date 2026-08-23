class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long current=0,total=0;
        
        for(int num:nums){
            if(num==0){
                current++;
                total+=current;
            }else{
                current=0;
            }
        }
        return total;
        
    }
};