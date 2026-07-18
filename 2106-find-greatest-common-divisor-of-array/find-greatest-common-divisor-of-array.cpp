class Solution {
public:
    int findGCD(vector<int>& nums) {
        int maximam=nums[0];
        int minimam=nums[0];
        for(int i=0;i<nums.size();i++){
            if(maximam<nums[i]){
                maximam=nums[i];
            }else if(minimam>nums[i]){
                minimam=nums[i];
            }
        }
        return gcd(maximam,minimam);
    }
};