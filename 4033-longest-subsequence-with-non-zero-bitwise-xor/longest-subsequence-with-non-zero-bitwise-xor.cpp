class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int total=0;
        bool has_nonzero=false;

        for(int num:nums){
            total^=num;

            if(num !=0){
                has_nonzero=true;
            }
        }
        if(total !=0){
            return nums.size();
        }
        if(has_nonzero){
            return nums.size()-1;
        }
        return 0;
    }
};