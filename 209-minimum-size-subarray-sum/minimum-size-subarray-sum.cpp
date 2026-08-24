class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int minimam=INT_MAX;
        int left=0;
        int current_sum=0;
        

        for(int i=0;i<n;i++){
            current_sum+=nums[i];

            while(current_sum>=target){
                minimam=min(minimam,i-left+1);
                current_sum-=nums[left];
                left++;
            }
        }
        return (minimam==INT_MAX)?0 : minimam;
    }
};