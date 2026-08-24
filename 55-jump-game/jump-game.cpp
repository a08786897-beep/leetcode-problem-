class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxjump=0;
        int n=nums.size();

        for(int i=0;i<n;i++){
            if(i>maxjump){
                return false;
            }
            maxjump=max(maxjump,i+nums[i]);

            if(maxjump>=n-1){
                return true;
            }
        }
        return false;
    }
};