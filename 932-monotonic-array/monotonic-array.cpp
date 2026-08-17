class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool incressing=true;
        bool decressing=true;

        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]>nums[i+1]){
                incressing=false;
            }
            if(nums[i]<nums[i+1]){
                decressing=false;
            }
        }
        return incressing || decressing;

    }
};