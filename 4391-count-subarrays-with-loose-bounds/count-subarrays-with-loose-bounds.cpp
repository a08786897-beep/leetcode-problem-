class Solution {

public:

    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long total_sub=0;
        long long curr_len=0;

        for(int num:nums){
            if(num >= minK && num <= maxK){
                curr_len++;
                total_sub+=curr_len;
            }else{
                curr_len=0;
            }
        }
        return total_sub;

    }

};