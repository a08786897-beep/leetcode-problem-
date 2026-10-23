class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int ans=-1;
        bool sored=true;

        for(int i=0;i<nums.size();i++){
            if(nums[i]!=i){
                ans &=nums[i];
                sored=false;
            }
        }
        return sored ? 0 : ans;
    }
};